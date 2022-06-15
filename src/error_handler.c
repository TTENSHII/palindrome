#include "palindrome.h"

static void check_if_p_is_palindrome(data_t *data)
{
    char *str = NULL;
    char *str_rev = NULL;
    int nb = data->number;

    if (data->p_flag != true) return;

    nb = convert_number_base(nb, 10, data->base);
    str = my_itoa(nb);
    str_rev = strdup(str);
    str_rev = my_strrev(str_rev);
    if (strcmp(str, str_rev) != 0) {
        printf("%d is not a palindrome.\n", data->number);
        free(str);
        free(str_rev);
        free_data(data);
        exit(84);
    }
    free(str);
    free(str_rev);
}

static void check_imin_imax(data_t *data)
{
    if (data->imin < 0 || data->imax < 0) {
        printf("Error: imin and imax must be >= 0\n");
        free_data(data);
        exit(84);
    }
    if (data->imin > data->imax) {
        printf("Error: imin must be <= imax\n");
        free_data(data);
        exit(84);
    }
}

static void check_options(data_t *data, int argc, char **argv)
{
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

static void check_parameters(data_t *data, char **argv)
{
    if (data->h_flag == true)
        display_help(argv[0], data);
    if (data->base < 2 || data->base > 10) {
        printf("Error: base must be between 2 and 10\n");
        free_data(data);
        exit(84);
    }
    if (data->number < 0) {
        printf("Error: number must be positive\n");
        free_data(data);
        exit(84);
    }
}

void error_handler(data_t *data, int argc, char **argv)
{
    check_parameters(data, argv);
    check_options(data, argc, argv);
    check_if_p_is_palindrome(data);
    check_imin_imax(data);
}
