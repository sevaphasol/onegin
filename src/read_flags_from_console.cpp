#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "colourful_print.h"
#include "read_flags_from_console.h"

void flags_input_getopt(const int argc, char* argv[]) // not const char* because getopt_long get char*
{
	while (true)
	{
        int option_index = 0;
		const struct option long_options[] =
		{
			{"help", no_argument, NULL, HELP},
		};

		// char* const* argv_for_getopt = (char* const*) argv;

		int c = getopt_long(argc, argv, "h", long_options, &option_index);

		if (c == -1)
			break;

		switch (c)
		{
			case HELP:
			case 'h':
				flag_help();
				break;

			default:
				red_print(stderr, "Error\n");
        }
	}
}

void flag_help()
{
	printf("bello");
    yellow_print(stdout, "\nHelp information \n"
						 "\nThis programm will sort your text\n"
						 "\nEnter two file names\n"
						 "build/onegin input_file output_file\n"
						 "\nIn case of incorrect using programm will use default files\n"
						 "\nDefault file input — onegin.txt\n"
						 "Default file output — sorted_onegin.txt\n\n");
}
