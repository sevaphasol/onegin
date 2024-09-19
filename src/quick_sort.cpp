#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "quick_sort.h"
#include "colorful_print.h"

void quick_sort(void* arr, int count, size_t size, int(* comp)(const void*, const void*))
{
    char* arr_char_ptr = (char*) arr;

    if (count > 1)
    {
        int middle_index = partition(arr_char_ptr, count, size, comp);

        quick_sort(arr_char_ptr                          , middle_index            , size, comp);
        quick_sort(arr_char_ptr + (middle_index + 1)*size, count - middle_index - 1, size, comp);
    }
}

int partition(char* arr, int count, size_t size, int(* comp)(const void*, const void*))
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
        if (left_index == middle_index)
        {
            right_index--;
        }

        else if (right_index == middle_index)
        {
            left_index++;
        }
        else
        {
            left_index++;
            right_index--;
        }
    }

    return middle_index;
}

int find_left(char* arr, size_t size, int left_index, int middle_index, int(* comp)(const void *, const void*))
{
    while (comp((void*)(arr + left_index * size), (void*)(arr + middle_index * size)) < 0)
    {
        left_index++;
    }
    return left_index;
}

int find_right(char* arr, size_t size, int right_index, int middle_index, int(* comp)(const void *, const void*))
{
    while (comp((void*)(arr + right_index*size), (void*)(arr + middle_index*size)) > 0)
    {
        right_index--;
    }
    return right_index;
}

int swap_left_and_right(char* arr, size_t size, int left_index, int right_index, int middle_index)
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

void swap_elems(void* ptr1_void, void* ptr2_void, size_t size)
{
    char* ptr1 = (char*) ptr1_void;
    char* ptr2 = (char*) ptr2_void;

    long long temp8 = 0;
    int       temp4 = 0;
    short     temp2 = 0;
    char      temp1 = 0;

    for (int i = 0; i < size; i++)
    {
        if (size - i >= 8)
        {
            temp8 = *((long long*)(ptr1 + i));
            *((long long*)(ptr1 + i)) = *((long long*)(ptr2 + i));
            *((long long*) (ptr2 + i)) = temp8;
            i += 7;
        }
        else if (size - i >= 4)
        {
            temp4 = *((int*) (ptr1 + i));
            *((int*) (ptr1 + i)) = *((int*) (ptr2 + i));
            *((int*) (ptr2 + i)) = temp4;
            i += 3;
        }
        else if (size - i >= 2)
        {
            temp2 = *((short*) (ptr1 + i));
            *((short*) (ptr1 + i)) = *((short*) (ptr2 + i));
            *((short*) (ptr2 + i)) = temp2;
            i += 1;
        }
        else
        {
            temp1 = *(ptr1 + i);
            *(ptr1 + i) = *(ptr2 + i);
            *(ptr2 + i) = temp1;
        }
    }
}
