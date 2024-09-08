#include <stdio.h>
#include "output.h"
#include "data.h"

int output(data_t* data)
{
    if (data_validation(data) == DATA_INVALID)
    {
        return -1;
    }

    for (int i = 0; i < data->n_strings; i++)
    {
        printf("%s\n", data->addr[i]);
    }

    return 0;
}
