#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "colorful_print.h" //TODO error in naming (colorful_print.h)

void color_print(FILE* file, const char *color_code, const char *str, ...)
{
	if (file == NULL)
	{
		exit(-1);
	}

	va_list list;
    va_start(list, str);

	set_color(file, color_code);

    vfprintf(file, str, list);

	reset_color(file);

    va_end(list);
}

void set_color(FILE* file, const char *color_code)
{
	fprintf(file, "%s", color_code);
}

void reset_color(FILE* file)
{
	fprintf(file, WHITE_CODE);
}
