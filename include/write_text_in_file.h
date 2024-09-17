#include "text_struct.h"

#ifndef WRITE_TEXT_IN_FILE_H__
#define WRITE_TEXT_IN_FILE_H__

int write_text_in_closed_file(const char* output_file, text_t* text);

int multiple_write_and_sort_text_in_closed_file(const char* output_file, text_t* text);

int write_text_in_opened_file(FILE* output_file_ptr, text_t* text);

#endif // WRITE_TEXT_IN_FILE_H__
