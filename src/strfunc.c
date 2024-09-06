#include "strfunc.h"
#include <string.h>

int my_strcmp(const char* str1, const char* str2, bool reversed)
{
    if (!reversed)
    {
        return strcmp(str1, str2);
    }
    else
    {
        return reverse_strcmp(str1, str2);
    }
    return 0;
}

int reverse_strcmp(const char* str1, const char* str2)
{
    const char* str1_end = str1 + my_size_of(str1);
    const char* str2_end = str2 + my_size_of(str2);

    for ( ; *str1_end == *str2_end; str1_end--, str2_end--)
        if (str1_end == str1 && str2_end == str2)
            return 0;
        else if (str1_end == str1 && str2_end != str2)
            return -1;
        else if (str1_end != str1 && str2_end == str2)
            return 1;
    return *str1_end - *str2_end;
}

size_t my_size_of(const char* str)
{
    size_t size = 0;
    for ( ; str[size] != '\0'; size++)
        ;
    return size;
}
