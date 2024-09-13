#ifndef READ_FLAGS_FROM_CONSOLE_H__
#define READ_FLAGS_FROM_CONSOLE_H__

enum long_option_vals
{
	HELP = 0,
};

void flag_help();

void flags_input_getopt(const int argc, char *argv[]);

#endif // READ_FLAGS_FROM_CONSOLE_H__
