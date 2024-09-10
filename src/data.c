#include "data.h"

int data_validation(data_t* data)
{
    if (data->strings == NULL)
    {
        return DATA_INVALID;
    }

    if (data->addr == NULL)
    {
        return DATA_INVALID;
    }

    if (data->n_strings < 0)
    {
        return DATA_INVALID;
    }

    return DATA_VALID;
}
