#include "text_struct.h"

#ifndef SORT_TEXT_H__
#define SORT_TEXT_H__

void sort_text(void (*sort)(void* ptr, const int count, const int size, int (*comp)(const void*, const void*)), void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*));

int bubble_sort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*));

int select_sort(text_t* text);

int input_sort(text_t* text);

int quick_sort(text_t* text);

int swap_string_ptrs(const char** p1, const char** p2);

void quick_sort(void* arr, int const count, const int size, int(* comp)(const void*, const void*));

int partition(char* arr, int const count, const int size, int(* comp)(const void*, const void*));

int find_left(char* arr, const int size, int left_index, int middle_value, int(* comp)(const void *, const void*));

int find_right(char* arr, const int size, int right_index, int middle_value, int(* comp)(const void *, const void*));

int swap_left_and_right(char* arr, const int size, int left_index, int right_index, int middle_index);

void swap_elems(void* ptr1_void, void* ptr2_void, const int size);

#endif // SORT_TEXT_H__
