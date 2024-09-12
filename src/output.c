#include <stdio.h>
#include <assert.h>
#include "output.h"
#include "data.h"

int output(FILE* file_ptr, data_t* data)
{
    if (data_validation(data) == DATA_INVALID)
    {
        return -1;
    }

    if (file_ptr == NULL)
    {
        return -1;
    }

    for (int i = 0; i < data->n_strings; i++)
    {
        assert(data->addr[i] != NULL);

        if (data->addr[i][0] != '\0')
        {
            fputs(data->addr[i], file_ptr);
            fputs("\n", file_ptr);
        }
    }

    return 0;
}
