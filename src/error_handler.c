#include "palindrome.h"

void error_handler(data_t *data, int argc, char **argv)
{
    if (data->base < 2 || data->base > 10)
       data->base = 10;

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
