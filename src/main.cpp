#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "error_codes.h"
#include "text_struct.h"
#include "read_text_from_file.h"
#include "write_text_in_file.h"
#include "quick_sort.h"
#include "string_compare_functions.h"
#include "colorful_print.h"
#include "debug_assert.h"

static const char* DEFAULT_INPUT_FILE  = "onegin.txt";
static const char* DEFAULT_OUTPUT_FILE = "sorted_onegin.txt";

int main(const int argc, const char* argv[])
{
    const char* input_file  = DEFAULT_INPUT_FILE;
    const char* output_file = DEFAULT_OUTPUT_FILE;

    text_t text = {0};

    if (read_text_out_of_file(argc, argv, &input_file, &output_file, &text) == READING_FAILURE)
    {
        red_print(stderr, "File reading error\n\n");
        return READING_FAILURE;
    }

    if (multiple_write_and_sort_text_in_closed_file(output_file, &text) == WRITING_FAILURE)
    {
        red_print(stderr, "File writing error\n\n");
        return WRITING_FAILURE;
    }

    text_free(&text);

    return 0;
}
