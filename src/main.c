#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_codes.h"
#include "text_struct.h"
#include "read_text_from_file.h"
#include "write_text_in_file.h"
#include "sort_text.h"
#include "string_compare_functions.h"
#include "colourful_print.h"

static const char* DEFAULT_INPUT_FILE  = "onegin.txt";
static const char* DEFAULT_OUTPUT_FILE = "sorted_onegin.txt";

int main(const int argc, char* argv[]) // not const char* because getopt_long get char*
{
    const char* input_file  = DEFAULT_INPUT_FILE;
    const char* output_file = DEFAULT_OUTPUT_FILE;

    text_t text = {0};

    if (read_text_out_of_file(argc, argv, input_file, output_file, &text) == -1)
    {
        red_print(stderr, "File reading error\n");
        return READING_FAILURE;
    }

    quick_sort(text.addr, text.n_strings, sizeof(char*), &my_strcmp);

    if (write_text_in_file(output_file, &text) == -1)
    {
        red_print(stderr, "File writing error\n");
        return WRITING_FAILURE;
    }

    return 0;
}
