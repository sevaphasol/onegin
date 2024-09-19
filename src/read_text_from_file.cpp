#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include "read_text_from_file.h"
#include "read_flags_from_console.h"
#include "colorful_print.h"
#include "error_codes.h"

int read_text_out_of_file(const int argc, const char* argv[], const char** input_file, const char** output_file, text_t* const text)
{
    if (argv == NULL || text == NULL)
    {
        return READING_FAILURE;
    }

    FILE *input_file_ptr = NULL;

    if (open_file(argc, argv, input_file, output_file, &input_file_ptr) == OPEN_FILE_FAILURE)
    {
        return READING_FAILURE;
    }

    if (input_file_ptr == NULL)
    {
        return READING_FAILURE;
    }

    if (get_file_size(input_file_ptr, text) == GET_FILE_SIZE_FAILURE)
    {
        return READING_FAILURE;
    }

    if (make_text(input_file_ptr, text) ==  ALLOCATE_FAILURE)
    {
        return READING_FAILURE;
    }

    fread(text->strings, sizeof(char), text->file_byte_size, input_file_ptr);

    if (make_addr(text) == ALLOCATE_FAILURE)
    {
        return READING_FAILURE;
    }

    if (fill_addr(text) == FILL_ADDR_FAILURE)
    {
        return READING_FAILURE;
    }

    fclose(input_file_ptr);

    return 0;
}

int open_file(const int argc, const char* argv[], const char** input_file, const char** output_file, FILE** input_file_ptr)
{
    if (argc == 3)
    {
        *input_file  = argv[1];
        *output_file = argv[2];
    }
    else if (argc != 1)
    {
        yellow_print(stdout, "\nHelp information: \n"
						     "\nThis programm will sort your text\n"
						     "\nEnter two file names in console: "
						     "build/onegin input_file output_file\n"
						     "\nIn case of void input programm will use default files\n"
						     "\nDefault file input — onegin.txt\n"
						     "Default file output — sorted_onegin.txt\n");

        red_print(stderr, "\nFlags reading error\n");

        return OPEN_FILE_FAILURE;
    }

    *input_file_ptr = fopen(*input_file, "r");

    // flags_input_getopt(argc, argv);

    if (input_file_ptr == NULL)
    {
        red_print(stderr, "\nFile opening error\n");
        return OPEN_FILE_FAILURE;
    }

    return 0;
}

int get_file_size(FILE* const file_ptr, text_t* const text)
{
    struct stat file_status;

    if (fstat(fileno(file_ptr), &file_status) < 0)
    {
        return GET_FILE_SIZE_FAILURE;
    }

    text->file_byte_size = file_status.st_size;

    return 0;
}

int make_text(FILE* const file_ptr, text_t* const text)
{
    text->strings = (char*) calloc(text->file_byte_size, sizeof(char));
    text->file_ptr = file_ptr;

    if (text == NULL)
    {
        return ALLOCATE_FAILURE;
    }

    return 0;
}

int make_addr(text_t* const text)
{
    int n_strings = 0;

    for (int i = 0; i < text->file_byte_size; i++)
    {
        if (text->strings[i] == '\n')
        {
            text->strings[i] = '\0';
            n_strings++;
        }
    }

    text->n_strings = n_strings;

    text->struct_strings = (string_t*) calloc(n_strings, sizeof(string_t));

    if (text->struct_strings == NULL)
    {
        free(text->strings);
        return ALLOCATE_FAILURE;
    }

    text->addr = (string_t**) calloc(n_strings, sizeof(string_t*));

    if (text->addr == NULL)
    {
        free(text->strings);
        free(text->struct_strings);

        return ALLOCATE_FAILURE;
    }

    return 0;
}

int fill_addr(text_t* const text)
{
    if (text_validation(text) == TEXT_INVALID)
    {
        printf("asd\n");
        return FILL_ADDR_FAILURE;
    }

    int string_index = 0;
    int left = -1; // for right length if first string contains one sign

    (text->struct_strings[0]).string_ptr = text->strings;

    (text->struct_strings[0]).origin_number = string_index;

    text->addr[0] = &(text->struct_strings[0]);

    for (int i = 1; i < text->file_byte_size; i++)
    {
        if (text->strings[i] == '\0')
        {
            (text->struct_strings[string_index]).string_ptr = text->strings + i + 1;

            (text->struct_strings[string_index]).length = i - left - 1;

            text->addr[string_index] = &(text->struct_strings[string_index]);

            left = i;

            string_index++;

            (text->struct_strings[string_index]).string_ptr = text->strings + i + 1;

            (text->struct_strings[string_index]).origin_number = string_index;

            text->addr[string_index] = &(text->struct_strings[string_index]);
        }
    }

    return 0;
}
