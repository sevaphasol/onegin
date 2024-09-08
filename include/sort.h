#include "data.h"

#ifndef SORT_H__
#define SORT_H__

int bubble_sort(data_t* data, int (*func)(const char*, const char*));

int select_sort(data_t* data);

int input_sort(data_t* data);

int quick_sort(data_t* data);

int swap_string_ptrs(const char** p1, const char** p2);

#endif
