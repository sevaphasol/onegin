#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "text_struct.h"
#include "string_compare_functions.h"
#include "debug_assert.h"

int reverse_strcmp(const void* str1_void, const void* str2_void)
{
    D_ASSERT(str1_void != NULL);
    D_ASSERT(str2_void != NULL);

    const char* str1 = (*((const string_t* const*) str1_void))->string_ptr;
    int length1 = (*((const string_t* const*) str1_void))->length;

    const char* str2 = (*((const string_t* const*) str2_void))->string_ptr;
    int length2 = (*((const string_t* const*) str1_void))->length;

    D_ASSERT(str1 != NULL);
    D_ASSERT(str2 != NULL);

    const char* str1_end = str1 + length1;
    const char* str2_end = str2 + length2;

    for ( ; *str1_end == *str2_end; str1_end--, str2_end--)
    {
        D_ASSERT(str1_end >= str1);
        D_ASSERT(str2_end >= str2);

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
    D_ASSERT(str1_void != NULL);
    D_ASSERT(str2_void != NULL);

    const char* str1 = (*((const string_t* const*) str1_void))->string_ptr;
    int length1 = (*((const string_t* const*) str1_void))->length;

    const char* str2 = (*((const string_t* const*) str2_void))->string_ptr;
    int length2 = (*((const string_t* const*) str2_void))->length;

    D_ASSERT(str1 != NULL);
    D_ASSERT(str2 != NULL);

    const char* str1_end = str1 + length1;
    const char* str2_end = str2 + length2;

    if (!length1)
    {
        return 0;
    }

    if (!length2)
    {
        return 0;
    }

    while (true)
    {
        D_ASSERT(str1_end >= str1);
        D_ASSERT(str2_end >= str2);

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

        D_ASSERT(str1_end >= str1);
        D_ASSERT(str2_end >= str2);
        while (str1_end != str1 && !isalpha(*str1_end))
        {
            D_ASSERT(str1_end >= str1);
            D_ASSERT(str2_end >= str2);
            str1_end--;
        }

        D_ASSERT(str1_end >= str1);
        D_ASSERT(str2_end >= str2);

        while (str2_end != str2 && !isalpha(*str2_end))
        {
            D_ASSERT(str1_end >= str1);
            D_ASSERT(str2_end >= str2);
            str2_end--;
        }

        D_ASSERT(str1_end >= str1);
        D_ASSERT(str2_end >= str2);

        if(*str1_end != *str2_end)
        {
            D_ASSERT(str1_end >= str1);
            D_ASSERT(str2_end >= str2);
            break;
        }

        if (str1_end == str1 || str2_end == str2)
        {
            break;
        }

        D_ASSERT(str1_end > str1);
        D_ASSERT(str2_end > str2);
        str1_end--, str2_end--;

    }

    return *str1_end - *str2_end;
}

int my_strcmp(const void* str1_void, const void* str2_void)
{
    return strcmp((*((const string_t* const*) str1_void))->string_ptr, (*((const string_t* const*) str2_void))->string_ptr);
}

int only_letter_strcmp(const void* str1_void, const void* str2_void)
{
    D_ASSERT(str1_void != NULL);
    D_ASSERT(str2_void != NULL);

    const char* str1 = (*((const string_t* const*) str1_void))->string_ptr;
    const char* str2 = (*((const string_t* const*) str2_void))->string_ptr;

    D_ASSERT(str1 != NULL);
    D_ASSERT(str2 != NULL);

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

int origin_number_compare(const void* void_ptr1, const void* void_ptr2)
{
    return (*((const string_t* const*) void_ptr1))->origin_number - (*((const string_t* const*) void_ptr2))->origin_number;
}
