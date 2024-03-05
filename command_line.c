#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "command_line.h"

void usage(const char* program_name, int exit_code) {
    fprintf(stderr, "Usage: %s [--letters chars] [--dict filename] [--min-len numletters]\n", program_name);
    exit(exit_code);
}

void commandLineParsing(int argc, char** argv, CommandLineParams* params) {
    int opt;

    int letters_set = 0;
    int dict_set = 0;
    int min_len_set = 0;

    struct option long_options[] = {
        {"letters",     required_argument, 0, 'l'},
        {"dict",        required_argument, 0, 'd'},
        {"min-len",     required_argument, 0, 'm'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "l:d:m:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'l':
                if (letters_set) {
                    usage(argv[0], 2);
                }

                if (!is_alpha_string(optarg)) {
                    exit(2);
                }

                if (strlen(optarg) > 12) {
                    exit(2);
                }


                params->letters = optarg;
                letters_set = 1;
                break;
            case 'd':
                if (dict_set) {
                    usage(argv[0], 2);
                }

                params->dict_path = optarg;
                dict_set = 1;
                break;
            case 'm':
                if (min_len_set) {
                    usage(argv[0], 2);
                }

                if (!is_digit_string(optarg)) {
                    exit(10);
                }

                params->min_len = atoi(optarg);

                if (params->min_len > 5 || params->min_len < 2) {
                    exit(10);
                }

                min_len_set = 1;
                break;
            default:
                usage(argv[0], 2);
        }
    }

    if (letters_set) {
        if (strlen(params->letters) < params->min_len) {
            exit(2);
        }
    }
}