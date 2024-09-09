#ifndef FLAGS_H__
#define FLAGS_H__

enum long_option_vals
{
	HELP = 0,
};

void flags_input(int argc, char *argv[]);

void flag_help();

void flags_input_getopt(const int argc, char *argv[]);

#endif // FLAGS_H__
