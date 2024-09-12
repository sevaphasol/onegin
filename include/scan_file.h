#include <stdio.h>
#include "data.h"

#ifndef SCAN_FILE_H__
#define SCAN_FILE_H__

int read_text_out_of_file(FILE* const file_ptr, data_t* const data);

int make_data(FILE* const file_ptr, data_t* const data);

int make_addr(data_t* const data);

int fill_addr(data_t* const data);

int get_file_size(FILE* const file_ptr, data_t* const data);

#endif // SCAN_FILE_H__
