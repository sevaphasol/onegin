#include <stdio.h>

#ifndef TEXT_STRUCT_H__
#define TEXT_STRUCT_H__

typedef struct Text
{
    char* strings;
    int n_strings;
    char** addr;
    FILE* file_ptr;
    long long file_byte_size;
} text_t;

typedef struct String
{
    char* string_ptr;
    int length;
} string_t;

enum text_validation_values
{
    DATA_INVALID = -1,
    DATA_VALID = 0,
};

int text_validation(text_t* text);

#endif // TEXT_STRUCT_H__
