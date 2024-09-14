#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "quick_sort.h"
#include "colourful_print.h"

void quick_sort(void* arr, const int count, const int size, int(* comp)(const void *, const void*))
{
    char* arr_char_ptr = (char*) arr;

    if (count > 1)
    {
        int middle_index = partition(arr_char_ptr, count, size, comp);

        quick_sort(arr_char_ptr                          , middle_index            , size, comp);
        quick_sort(arr_char_ptr + (middle_index + 1)*size, count - middle_index - 1, size, comp);
    }
}

int partition(char* arr, const int count, const int size, int(* comp)(const void*, const void*))
{
    int left_index = 0;
    int right_index = count - 1;
    int middle_index = (left_index + right_index) / 2;

    int middle_value = *(arr + middle_index*size);

    while (left_index < right_index)
    {
        left_index = find_left(arr, size, left_index, middle_index, comp);

        right_index = find_right(arr, size, right_index, middle_index, comp);

        middle_index = swap_left_and_right(arr, size, left_index, right_index, middle_index);

        left_index++;
        right_index--;
    }

    return middle_index;
}

int find_left(char* arr, const int size, int left_index, int middle_index, int(* comp)(const void *, const void*))
{
    while (comp((void*)(arr + left_index*size), (void*)(arr + middle_index*size)) < 0)
    {
        left_index++;
    }
    return left_index;
}

int find_right(char* arr, const int size, int right_index, int middle_index, int(* comp)(const void *, const void*))
{
    while (comp((void*)(arr + right_index*size), (void*)(arr + middle_index*size)) > 0)
    {
        right_index--;
    }
    return right_index;
}

int swap_left_and_right(char* arr, const int size, int left_index, int right_index, int middle_index)
{
    if (left_index != right_index)
    {
        if(left_index == middle_index)
        {
            middle_index = right_index;
        }

        else if(right_index == middle_index)
        {
            middle_index = left_index;
        }

        swap_elems((void*)(arr + left_index*size), (void*)(arr + right_index*size), size);
    }

    return middle_index;
}

void swap_elems(void* ptr1_void, void* ptr2_void, const int size)
{
    char* ptr1 = (char*) ptr1_void;
    char* ptr2 = (char*) ptr2_void;

    char temp = 0;

    for (int i = 0; i < size; i++)
    {
        temp = *(ptr1 + i);
        *(ptr1 + i) = *(ptr2 + i);
        *(ptr2 + i) = temp;
    }
}
