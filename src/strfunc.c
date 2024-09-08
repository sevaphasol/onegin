#include <stdlib.h>
#include <string.h>
#include "strfunc.h"

size_t my_size_of(const char* str)
{
    size_t size = 0;

    for ( ; str[size] != '\0'; size++)
        ;

    return size;
}

int reverse_strcmp(const char* str1, const char* str2)
{
    const char* str1_end = str1 + my_size_of(str1);
    const char* str2_end = str2 + my_size_of(str2);

    for ( ; *str1_end == *str2_end; str1_end--, str2_end--)
    {
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

// int only_letter_strcmp(const char* str1, const char* str2)
// {
//     int index1 = 0;
//     int index2 = 0;
//     while (true)
//     {
//         while (!isaplha(str1[index1]) && str1[index] !='\0')
//         {
//             index1++;
//         }
//
//         while (!isaplha(str2[index2]) && str1[index] !='\0')
//         {
//             index2++;
//         }
//
//         if (str1[index1] != str2[index2])
//         {
//             break;
//         }
//
//
//     }
// }
