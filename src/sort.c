#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "sort.h"
#include "colors.h"

int swap_string_ptrs(char** p1, char** p2)
{
    if (p1 == NULL || p2 == NULL)
        return -1;

    char* tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

    return 0;
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
