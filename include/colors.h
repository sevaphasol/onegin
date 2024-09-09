#ifndef COLORS_H__
#define COLORS_H__

#define WHITE_CODE     "\033[0m"
#define RED_CODE       "\033[31m"
#define GREEN_CODE     "\033[32m"
#define YELLOW_CODE    "\033[33m"
#define BLUE_CODE      "\033[34m"
#define PURPLE_CODE    "\033[35m"
#define TURQUOISE_CODE "\033[36m"

#define red_print(str,       ...) color_print(RED_CODE,       str, ##__VA_ARGS__)
#define green_print(str,     ...) color_print(GREEN_CODE,     str, ##__VA_ARGS__)
#define yellow_print(str,    ...) color_print(YELLOW_CODE,    str, ##__VA_ARGS__)
#define blue_print(str,      ...) color_print(BLUE_CODE,      str, ##__VA_ARGS__)
#define purple_print(str,    ...) color_print(PURPLE_CODE,    str, ##__VA_ARGS__)
#define turquoise_print(str, ...) color_print(TURQUOISE_CODE, str, ##__VA_ARGS__)

void color_print(const char *color_code, const char *str, ...);

void set_color(const char *color_code);

void reset_color();

#endif // COLORS_H__
