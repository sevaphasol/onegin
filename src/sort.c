// #include "sort.h"
// #include <string.h>
// #include <stdlib.h>
//
// void swap_strings(const char* p1, const char* p2)
// {
//     if (p1 == NULL || p2 == NULL)
//         exit(0);
//
//     const char* tmp = p1;
//     p1 = p2;
//     p2 = tmp;
// }
//
// void swap_ints(int* a, int* b)
// {
//     if (a == NULL || b == NULL)
//         exit(0);
//
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
//
// void bubble_sort(data_t* data)
// {
//     for (int i = 1; i < data->maxlength; i++)
//         for (int j = 0; j < data->maxlength - 1 - i; j++)
//             if (strcmp(data->strings[data->index[j]], data->strings[data->index[j+1]]) > 0)
//                 swap_ints(&data->index[j], &data->index[j+1]);
// }
//
// // int min_element_index(data_t* data)
// // {
// //
// // }
// //
// // void select_sort(data_t* data)
// // {
// //     data_t* sorted_data = (data_t *)calloc(1, sizeof(data_t));
// //
// // }
