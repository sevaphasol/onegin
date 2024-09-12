#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "strfunc.h"

int reverse_strcmp(const char* str1, const char* str2)
{
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

int only_letter_reverse_strcmp(const char* str1, const char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    const char* str1_end = str1 + strlen(str1);
    const char* str2_end = str2 + strlen(str2);

    while (true)
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

        while (!isalpha(*str1_end) && str1_end != str1)
        {
            str1_end--;
        }

        while (!isalpha(*str2_end) && str2_end != str2)
        {
            str2_end--;
        }

        if(*str1_end != *str2_end)
        {
            break;
        }

        str1_end--, str2_end--;
    }

    return *str1_end - *str2_end;
}

int my_strcmp(const void* str1, const void* str2)
{
    return strcmp((const char*) str1, (const char*) str2);
}

int only_letter_strcmp(const char* str1, const char* str2)
{
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
