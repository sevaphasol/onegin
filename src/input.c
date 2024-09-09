#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include "input.h"

int input(FILE* const file_ptr, data_t* const data)
{
    if (file_ptr == NULL)
    {
        return -1;
    }

    long size = get_file_size(file_ptr);
    if (size == -1)
    {
        return -1;
    }

    data->strings = (char*)calloc(size, sizeof(char));
    if (data == NULL)
    {
        return -1;
    }

    fread(data->strings, sizeof(char), size, file_ptr);

    int n_strings = 0;

    for (int i = 0; i < size; i++)
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

    int string_index = 0;

    data->addr[0] = data->strings;

    for (int i = 1; i < size; i++)
    {
        if (data->strings[i] == '\0') // if (data->strings[i] == '\n' && data->strings[i-1] != '\0')
        {
            data->addr[++string_index] = data->strings + i + 1;
        }
    }

    return 0;
}

long get_file_size(FILE* const file_ptr)
{
    struct stat file_status;

    if (fstat(fileno(file_ptr), &file_status) < 0)
    {
        return -1;
    }

    return file_status.st_size;
}
