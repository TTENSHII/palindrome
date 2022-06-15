#include "palindrome.h"

static void display_help(char *executable, data_t *data)
{
    printf("USAGE\n\t%s  -n number -p palindrome ", executable);
    printf("[-b base] [-imin i] [-imax i]\n");
    printf("\nDESCRIPTION\n");
    printf("\t-n n\tinteger to be transformed (>=0)\n");
    printf("\t-p pal\tpalindromic number to be obtained");
    printf(" (incompatible with the -n option) (>=0)\n");
    printf("if defined, all fitting values of n will be output\n");
    printf("\t-b base\tbase in which the procedure will be\n");
    printf("\texecuted (1<b<=10) [def: 10]\n");
    printf("\t-imin i\tminimum number of iterations, (>=0) [def: 0]\n");
    printf("\t-imax i\tmaximum number of iterations,, (>=0) [def: 100]\n");
    free_data(data);
    exit(0);
}

void error_handler(data_t *data, int argc, char **argv)
{
    if (data->base < 2 || data->base > 10)
       data->base = 10;
    if (data->h_flag == true)
        display_help(argv[0], data);
    if (data->p_flag == true && data->n_flag == true) {
        dprintf(2, "Error: -p and -n are incompatible\n");
        free_data(data);
        exit(84);
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' && argv[i - 1][0] != '-') {
            dprintf(2, "Invalid argument\n");
            free_data(data);
            exit(84);
        }
    }
}
