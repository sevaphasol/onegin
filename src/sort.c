#include "sort.h"
#include <string.h>
#include <stdlib.h>

int swap_string_ptrs(const char* p1, const char* p2)
{
    if (p1 == NULL || p2 == NULL)
        return -1;

    const char* tmp = p1;
    p1 = p2;
    p2 = tmp;

    return 0;
}

int bubble_sort(data_t* data, int (*func)(const char*, const char*))
{
    for (int i = 1; i < data->n_strings; i++)
    {
        for (int j = 0; j < data->n_strings - 1 - i; j++)
        {
            if (func(data->addr[j], data->addr[j+1]) > 0)
            {
                if (swap_string_ptrs(data->addr[j], data->addr[j+1]) == -1)
                {
                    return -1;
                }
            }
        }
    }
    return 0;
}
