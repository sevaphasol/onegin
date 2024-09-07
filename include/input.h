#include <stdio.h>
#include "data.h"

#ifndef INPUT_H__
#define INPUT_H__

int input(FILE* const file_ptr, data_t* const data);

long get_file_size(FILE* const file_ptr);

#endif // INPUT_H__
