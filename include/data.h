#include <stdio.h>

#ifndef DATA_H__
#define DATA_H__

typedef struct Data
{
    char* strings;
    int n_strings;
    char** addr;
} data_t;

typedef struct String
{
    char* string_ptr;
    int n_chars;
} string_t;

typedef enum data_validation_values
{
    DATA_INVALID = -1,
    DATA_VALID = 0,
} data_val_t;

int data_validation(data_t* data);

#endif
