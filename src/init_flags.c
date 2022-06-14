#include "palindrome.h"
#include <getopt.h>

void ini_flag(data_t *data, int argc, char **argv)
{
    int option = 0;
    char short_opts[] = "p:n:b:h";
    const struct option long_options [] = {
        {"imin", required_argument, NULL, 'i'},
        {"imax", required_argument, NULL, 'j'},
        {NULL, 0, NULL, 0}
    };

    while ((option = getopt_long_only(argc, argv, short_opts, long_options, NULL)) != - 1) {
        if (option == 'h')
            data->flags.h = true;
        if (option == 'p') {
            data->flags.p = true;
            data->flags.number = atoi(optarg);
        }
        if (option == 'n') {
            data->flags.n = true;
            data->flags.number = atoi(optarg);
        }
        if (option == 'b')
            data->flags.base = atoi(optarg);
        if (option == 'i')
            data->flags.imin = atoi(optarg);
        if (option == 'j')
            data->flags.imax = atoi(optarg);
        if (option == '?')
            exit(84);
    }
    if (data->flags.p == true && data->flags.n == true) {
        dprintf(2, "Error: -p and -n are incompatible\n");
        exit(84);
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            dprintf(2, "Error: %s: invalid option\n", argv[i]);
            exit(84);
        }
    }
}
