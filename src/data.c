#include <stdlib.h>
#include "data.h"

int data_validation(data_t* data)
{
    if (data->strings == NULL)
    {
        free(data->strings);
        free(data->addr);

        return DATA_INVALID;
    }

    if (data->addr == NULL)
    {
        free(data->strings);
        free(data->addr);

        return DATA_INVALID;
    }

    if (data->n_strings < 0)
    {
        return DATA_INVALID;
    }

    return DATA_VALID;
}
