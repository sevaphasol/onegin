#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include "scan_file.h"

int read_text_out_of_file(FILE* const file_ptr, data_t* const data)
{
    if (file_ptr == NULL || data == NULL)
    {
        return -1;
    }

    get_file_size(file_ptr, data);

    make_data(file_ptr, data);

    fread(data->strings, sizeof(char), data->file_byte_size, file_ptr);

    make_addr(data);

    fill_addr(data);

    return 0;
}

int get_file_size(FILE* const file_ptr, data_t* const data)
{
    struct stat file_status;

    if (fstat(fileno(file_ptr), &file_status) < 0)
    {
        return -1;
    }

    data->file_byte_size = file_status.st_size;

    return 0;
}

int make_data(FILE* const file_ptr, data_t* const data)
{
    data->strings = (char*)calloc(data->file_byte_size, sizeof(char));
    if (data == NULL)
    {
        return -1;
    }

    return 0;
}

int make_addr(data_t* const data)
{
    int n_strings = 0;

    for (int i = 0; i < data->file_byte_size; i++)
    {
        if (data->strings[i] == '\n')
        {
            data->strings[i] = '\0';
            n_strings++;
        }
    }

    data->n_strings = n_strings;

    data->addr = (char**)calloc(n_strings, sizeof(char*));
    if (data->addr == NULL)
    {
        free(data->strings);
        return -1;
    }

    return 0;
}

int fill_addr(data_t* const data)
{
    int string_index = 0;

    data->addr[0] = data->strings;

    for (int i = 1; i < data->file_byte_size; i++)
    {
        if (data->strings[i] == '\0') // if (data->strings[i] == '\n' && data->strings[i-1] != '\0')
        {
            data->addr[++string_index] = data->strings + i + 1;
        }
    }

    return 0;
}
