#include "data.h"

#ifndef SORT_H__
#define SORT_H__

int bubble_sort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*));

int select_sort(data_t* data);

int input_sort(data_t* data);

int quick_sort(data_t* data);

int swap_string_ptrs(const char** p1, const char** p2);

#endif
