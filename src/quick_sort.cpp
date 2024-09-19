#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "quick_sort.h"
#include "colorful_print.h"

void quick_sort(void* arr, int count, size_t size, int(* comp)(const void*, const void*))
{
    char* arr_char_ptr = (char*) arr;

    if (count > 3)
    {
        int middle_index = partition(arr_char_ptr, count, size, comp);

        quick_sort(arr_char_ptr                            , middle_index            , size, comp);
        quick_sort(arr_char_ptr + (middle_index + 1) * size, count - middle_index - 1, size, comp);
    }
    else if (count == 3)
    {
        sort_three_elems(arr_char_ptr, size, comp);
    }
    else if (count == 2)
    {
        sort_two_elems(arr_char_ptr, size, comp);
    }
}

int partition(char* arr, int count, size_t size, int(* comp)(const void*, const void*))
{
    int left_index = 0;

    int right_index = count - 1;

    srand((int) time(NULL));

    int middle_index = rand() % count;

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

    int pos = 0;

    while (pos < size)
    {
        if (size - pos >= 8)
        {
            swap(ptr1, ptr2, pos, long long);
            pos += 8;
        }
        else if (size - pos >= 4)
        {
            swap(ptr1, ptr2, pos, int);
            pos += 4;
        }
        else if (size - pos >= 2)
        {
            swap(ptr1, ptr2, pos, short);
            pos += 2;
        }
        else
        {
            swap(ptr1, ptr2, pos, char);
            pos += 1;
        }
    }
}

void sort_two_elems(char* arr, size_t size, int(* comp)(const void*, const void*))
{
    if (comp((void*) (arr), (void*) (arr + size)) > 0)
        {
            swap_elems((void*) arr, (void*) (arr + size), size);
        }
}

void sort_three_elems(char* arr, size_t size, int(* comp)(const void*, const void*))
{
    void* first  = (void*) arr;
    void* second = (void*) (arr + size);
    void* third  = (void*) (arr + size * 2);

    if (comp(first, second) > 0)
    {
        if (comp(first, third) > 0)
        {
            swap_elems(first, third, size);
        }

        sort_two_elems(arr, size, comp);
    }
    else
    {
        sort_two_elems(arr + size, size, comp);
    }
}

// int random_index(int count)
// {
//     static int n = count;
//     int t = (int) clock();
//     n = (t*n + t) % count;
//     return n;
// }
