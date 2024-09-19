#include "text_struct.h"

#ifndef SORT_TEXT_H__
#define SORT_TEXT_H__

#define swap(ptr1, ptr2, pos, type) ({               \
    type tmp = *((type*)(ptr1 + pos));               \
    *((type*)(ptr1 + pos)) = *((type*)(ptr2 + pos)); \
    *((type*) (ptr2 + pos)) = tmp;  })               \

void quick_sort(void* arr, int count, size_t size, int(* comp)(const void*, const void*));

int partition(char* arr, int count, size_t size, int(* comp)(const void*, const void*));

int find_left(char* arr, size_t size, int left_index, int middle_value, int(* comp)(const void *, const void*));

int find_right(char* arr, size_t size, int right_index, int middle_value, int(* comp)(const void *, const void*));

int swap_left_and_right(char* arr, size_t size, int left_index, int right_index, int middle_index);

void swap_elems(void* ptr1_void, void* ptr2_void, size_t size);

int random_index(int count);

void sort_two_elems(char* arr, size_t size, int(* comp)(const void*, const void*));

void sort_three_elems(char* arr, size_t size, int(* comp)(const void*, const void*));

#endif // SORT_TEXT_H__
