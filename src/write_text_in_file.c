#include <stdio.h>
#include <assert.h>
#include "write_text_in_file.h"
#include "text_struct.h"
#include "colourful_print.h"

int write_text_in_file(const char* output_file, text_t* text)
{
    FILE *output_file_ptr;
    output_file_ptr = fopen(output_file, "w");

    if (output_file_ptr == NULL)
    {
        red_print(stderr, "File opening error\n");
        return -1;
    }

    if (text_validation(text) == DATA_INVALID)
    {
        return -1;
    }

    for (int i = 0; i < text->n_strings; i++)
    {
        assert(text->addr[i] != NULL);

        if (text->addr[i][0] != '\0')
        {
            fputs(text->addr[i], output_file_ptr);
            fputs("\n", output_file_ptr);
        }
    }

    fclose(output_file_ptr);

    green_print(stdout, "Output in %s\n", output_file);

    return 0;
}
