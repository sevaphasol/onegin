#include <stdio.h>
#include "text_struct.h"

#ifndef READ_TEXT_FROM_FILE_H__
#define READ_TEXT_FROM_FILE_H__

int read_text_out_of_file(const int argc, char* argv[], const char** input_file, const char** output_file, text_t* const text);

int open_file(const int argc, char* argv[], const char** input_file, const char** output_file, FILE** input_file_ptr);

int make_text(FILE* const file_ptr, text_t* const text);

int make_addr(text_t* const text);

int fill_addr(text_t* const text);

int get_file_size(FILE* const file_ptr, text_t* const text);

#endif // READ_TEXT_FROM_FILE_H__
