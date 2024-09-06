#ifndef SORT_H__
#define SORT_H__

const int MAXLINE = 5;
const int HEIGHT = 10;

typedef struct Data{
    char strings[HEIGHT][MAXLINE];
    int index[HEIGHT];
    int height;
    int maxlength;
} data_t;

void bubble_sort(data_t* data);

void select_sort(data_t* data);

void input_sort(data_t* data);

void quick_sort(data_t* data);

void swap_strings(const char* p1, const char* p2);

void swap_ints(const int a, const int b);

#endif
