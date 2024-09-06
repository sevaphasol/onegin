#include "sort.h"
#include "strfunc.h"
#include <stdio.h>
#include <string.h>

void swap_strings(const char* p1, const char* p2)
{
    const char* tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void swap_ints(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(data_t* data)
{
    for (int i = 1; i < data->maxlength; i++)
        for (int j = 0; j < data->maxlength - 1 - i; j++)
            if (my_strcmp(data->strings[data->index[j]], data->strings[data->index[j+1]], false) > 0)
                swap_ints(&data->index[j], &data->index[j+1]);
}
