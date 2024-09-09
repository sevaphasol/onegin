#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "input.h"
#include "data.h"
#include "output.h"
#include "strfunc.h"
#include "colors.h"
#include "flags.h"

static const char* INPUT_FILE = "onegin.txt";
static const char* OUTPUT_FILE = "sorted_onegin.txt";

int main(const int argc, char* argv[])
{
    const char* input_file = INPUT_FILE;
    const char* output_file = OUTPUT_FILE;

    if (argc == 3)
    {
        input_file = argv[1];
        output_file = argv[2];
    }

    FILE *input_file_ptr;
    input_file_ptr = fopen(input_file, "r");

    flags_input_getopt(argc, argv);

    if (input_file_ptr == NULL)
    {
        red_print("File opening error\n");
        return -1;
    }

    data_t data = {0};

    if (input(input_file_ptr, &data) == -1)
    {
        red_print("File reading error\n");
        return -1;
    }

    fclose(input_file_ptr);

    if (bubble_sort(&data, &only_letter_reverse_strcmp) == -1)
    {
        red_print("Data sorting problem\n");
        return -1;
    }

    FILE *output_file_ptr;
    output_file_ptr = fopen(output_file, "w");

    if (output_file_ptr == NULL)
    {
        red_print("File opening error\n");
        return -1;
    }

    if (output(output_file_ptr, &data) == -1)
    {
        red_print("File writing error\n");
        return -1;
    }

    fclose(output_file_ptr);

    green_print("Output in %s\n", output_file);

    return 0;
}
