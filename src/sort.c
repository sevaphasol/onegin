#include <string.h>
#include <stdlib.h>
#include "sort.h"

int swap_string_ptrs(char** p1, char** p2)
{
    if (p1 == NULL || p2 == NULL)
        return -1;

    char* tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

    return 0;
}

int bubble_sort(data_t* data, int (*func)(const char*, const char*))
{
    if (data_validation(data) == DATA_INVALID)
        {
            return -1;
        }

    if (func == NULL)
    {
        return -1;
    }

    for (int i = 1; i < data->n_strings; i++)
    {
        for (int j = 0; j < data->n_strings - i; j++)
        {
            if (func(data->addr[j], data->addr[j+1]) > 0)
            {
                if (swap_string_ptrs(&data->addr[j], &data->addr[j+1]) == -1)
                {
                    return -1;
                }
            }
        }
    }
    return 0;
}
