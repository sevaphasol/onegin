#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "sort_text.h"
#include "colourful_print.h"

void sort_text(void (*sort)(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*)), void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    sort(ptr, count, size, comp);
}

int bubble_sort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    if (ptr == NULL)
    {
        red_print(stderr, "Data sorting problem %d\n", __LINE__);
        return -1;
    }

    if (comp == NULL)
    {
        red_print(stderr, "Data sorting problem %d\n", __LINE__);
        return -1;
    }

    char* temp = NULL;

    char *array_ptr = (char *) ptr;

    for (size_t i = 1; i < count; i++)
    {
        for (size_t j = 0; j < count - i; j++)
        {
            // assert(((char**)ptr)[j] != NULL);
            // assert(((char**)ptr)[j+1] != NULL);

            if ( *((char**) array_ptr + j) == NULL)
            {
                red_print(stderr, "Data sorting problem %d\n", __LINE__);
                return -1;
            }

            if ( *((char**) ptr + j + 1) == NULL)
            {
                red_print(stderr, "Data sorting problem %d\n", __LINE__);
                return -1;
            }

            if (comp(*((char**) ptr + j), (array_ptr + (j + 1) * size)) > 0)
            {
                temp = *((char**) ptr + j);
                // assert(temp != NULL);

                if (temp == NULL)
                {
                    red_print(stderr, "Data sorting problem %d\n", __LINE__);
                    return -1;
                }

                *((char**) ptr + j) = *((char**) ptr + j + 1);
                // assert(((char**)ptr)[j] != NULL);

                if (((char**) ptr)[j] == NULL)
                {
                    red_print(stderr, "Data sorting problem %d\n", __LINE__);
                    return -1;
                }

                *((char**) ptr + j + 1) = temp;
                // assert(((char**)ptr)[j+1] != NULL);

                if (*((char**) ptr + j + 1) == NULL)
                {
                    red_print(stderr, "Data sorting problem %d\n", __LINE__);
                    return -1;
                }
            }
        }
    }
    return 0;
}

int swap_string_ptrs(char** p1, char** p2)
{
    if (p1 == NULL || p2 == NULL)
        return -1;

    char* tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

    return 0;
}


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
    // printf("\n");

    int left_index = 0;
    int right_index = count - 1;
    int middle_index = (left_index + right_index) / 2;

    int middle_value = *(arr + middle_index*size);

    // color_arr_print(arr, count, size, middle_index, left_index, right_index);

    while (left_index < right_index)
    {
        left_index = find_left(arr, size, left_index, middle_index, comp);

        // printf("%d - %d\n", arr[left_index], left_index);

        right_index = find_right(arr, size, right_index, middle_index, comp);

        // printf("%d - %d\n", arr[right_index], right_index);

        // getchar();

        // color_arr_print(arr, count, size, middle_index, left_index, right_index);

        // printf("\nl - %d m - %d r - %d\n", left_index, middle_index, right_index);

        // if (*(arr + left_index*size) == *(arr + middle_index*size) && // bag with arr5
        //     *(arr + right_index*size) == *(arr + middle_index*size) &&
        //     left_index != right_index)
        // {
        //     if (left_index < middle_index)
        //     {
        //         left_index++;
        //         continue;
        //     }
        //     else if (right_index > middle_index)
        //     {
        //         right_index--;
        //         continue;
        //     }
        // }

        middle_index = swap_left_and_right(arr, size, left_index, right_index, middle_index);

        left_index++;
        right_index--;

        // getchar();

        // color_arr_print(arr, count, size, middle_index, left_index, right_index);

        // printf("\nl - %d m - %d r - %d\n", left_index, middle_index, right_index);
    }
    // printf("\n");

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

    char buf[size] = {0};

    for (int i = 0; i < size; i++)
    {
        buf[i] = *(ptr1 + i);
    }

    for (int i = 0; i < size; i++)
    {
        *(ptr1 + i) = *(ptr2 + i);
    }

    for (int i = 0; i < size; i++)
    {
        *(ptr2 + i) = buf[i];
    }
}
