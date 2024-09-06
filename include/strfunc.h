#include <stddef.h>

#ifndef STRFUNC_H__
#define STRFUNC_H__

int my_strcmp(const char* str1, const char* str2, bool reversed);

int reverse_strcmp(const char* str1, const char* str2);

size_t my_size_of(const char* str);

#endif // STRFUNC_H__
