#include <getopt.h>
#include "palindrome.h"

static void check_options(data_t *data, int option, char **argv)
{
    if (option == 'n') {
        data->n_flag = true;
        data->number = atoi(optarg);
    }
    if (option == 'p') {
        data->p_flag = true;
        data->number = atoi(optarg);
    }
}

static void check_flag(data_t *data, int option, char **argv)
{
    if (option == 'h')
        data->h_flag = true;
    if (option == 'i')
        data->imin = atoi(optarg);
    if (option == 'I')
        data->imax = atoi(optarg);
    if (option == 'b')
        data->base = atoi(optarg);
    if (option == '?')
        exit(84);
}

void init_options(data_t *data, int argc, char **argv)
{
    int option = 0;
    char short_opts[] = "p:n:b:h";
    const struct option long_options [] = {
        {"imin", required_argument, NULL, 'i'},
        {"imax", required_argument, NULL, 'I'},
        {NULL, 0, NULL, 0}
    };

    while ((option = getopt_long_only(argc,\
    argv, short_opts, long_options, NULL)) != - 1) {
        check_options(data, option, argv);
        check_flag(data, option, argv);
    }
}
