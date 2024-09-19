#ifndef COLORS_H__
#define COLORS_H__

#define WHITE_CODE     "\033[0m"
#define RED_CODE       "\033[31m"
#define GREEN_CODE     "\033[32m"
#define YELLOW_CODE    "\033[33m"
#define BLUE_CODE      "\033[34m"
#define PURPLE_CODE    "\033[35m"
#define TURQUOISE_CODE "\033[36m"

#define red_print(file, str,       ...) color_print(file, RED_CODE,       str, ##__VA_ARGS__)
#define green_print(file, str,     ...) color_print(file, GREEN_CODE,     str, ##__VA_ARGS__)
#define yellow_print(file, str,    ...) color_print(file, YELLOW_CODE,    str, ##__VA_ARGS__)
#define blue_print(file, str,      ...) color_print(file, BLUE_CODE,      str, ##__VA_ARGS__)
#define purple_print(file, str,    ...) color_print(file, PURPLE_CODE,    str, ##__VA_ARGS__)
#define turquoise_print(file, str, ...) color_print(file, TURQUOISE_CODE, str, ##__VA_ARGS__)

void color_print(FILE* file, const char *color_code, const char *str, ...);

void set_color(FILE* file, const char *color_code);

void reset_color(FILE* file);

#endif // COLORS_H__
