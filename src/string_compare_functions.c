#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "string_compare_functions.h"

int reverse_strcmp(const void* str1_void, const void* str2_void)
{
    assert(str1_void != NULL);
    assert(str2_void != NULL);

    const char* str1 = *((const char**) str1_void);
    const char* str2 = *((const char**) str2_void);

    assert(str1 != NULL);
    assert(str2 != NULL);

    const char* str1_end = str1 + strlen(str1);
    const char* str2_end = str2 + strlen(str2);

    for ( ; *str1_end == *str2_end; str1_end--, str2_end--)
    {
        assert(str1_end >= str1);
        assert(str2_end >= str2);

        if (str1_end == str1 && str2_end == str2)
        {
            return 0;
        }
        else if (str1_end == str1 && str2_end != str2)
        {
            return -1;
        }
        else if (str1_end != str1 && str2_end == str2)
        {
            return 1;
        }
    }

    return *str1_end - *str2_end;
}



int only_letter_reverse_strcmp(const void* str1_void, const void* str2_void)
{
    assert(str1_void != NULL);
    assert(str2_void != NULL);

    const char* str1 = *((const char**) str1_void);
    const char* str2 = *((const char**) str2_void);

    assert(str1 != NULL);
    assert(str2 != NULL);

    const char* str1_end = str1 + strlen(str1) - 1;
    const char* str2_end = str2 + strlen(str2) - 1;

    // printf("str1_end - %p str2_end - %p\n", str1_end, str2_end);
    // printf("str1 - %p str2 - %p\n", str1, str2);

    // printf("%s - %s", str1, str2);

    while (true)
    {
        assert(str1_end >= str1);
        assert(str2_end >= str2);

        printf("%d\n", __LINE__);
        if (str1_end == str1 && str2_end == str2)
        {
            return *str1_end - *str2_end;
        }
        else if (str1_end == str1 && str2_end > str2)
        {
            return -1;
        }
        else if (str1_end != str1 && str2_end == str2)
        {
            return 1;
        }

        printf("%d\n", __LINE__);


        while (str1_end > str1 + 1 && !isalpha(*str1_end))
        {
            str1_end--;
        }

        printf("%d\n", __LINE__);


        while (str2_end > str2 + 1 && !isalpha(*str2_end))
        {
            str2_end--;
        }

        printf("%d\n", __LINE__);


        printf("str1_end - %p str2_end - %p\n", str1_end, str2_end);
        printf("str1 - %p str2 - %p\n", str1, str2);

        if(*str1_end != *str2_end)
        {
            break;
        }

        printf("%d\n", __LINE__);


        if (str1_end == str1 || str2_end == str2)
        {
            break;
        }

        printf("%d\n", __LINE__);


        str1_end--, str2_end--;

        printf("%d\n", __LINE__);

    }

    printf("%d\n", __LINE__);

    return *str1_end - *str2_end;
}

int my_strcmp(const void* str1, const void* str2)
{
    return strcmp(*((const char**) str1), *((const char**) str2));
}

int only_letter_strcmp(const void* str1_void, const void* str2_void)
{
    assert(str1_void != NULL);
    assert(str2_void != NULL);

    const char* str1 = *((const char**) str1_void);
    const char* str2 = *((const char**) str2_void);

    assert(str1 != NULL);
    assert(str2 != NULL);

    while (true)
    {
        if (*str1 == '\0' || *str2 == '\0')
        {
            break;
        }

        while (!isalpha(*str1) && *str1 != '\0')
        {
            str1++;
        }

        while (!isalpha(*str2) && *str2 != '\0')
        {
            str2++;
        }

        if (*str1 != *str2)
        {
            break;
        }

        str1++, str2++;
    }
    return *str1 - *str2;
}

int int_compare(const void* a, const void* b)
{
    return *((const int*) a) - *((const int*) b);
}
