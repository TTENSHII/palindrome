#include <palindrome.h>

static void print_result(data_t *data, int save_nbr)
{
    if (strcmp(data->str, data->reversed_str) == 0) {
        printf("%d leads to ", save_nbr);
        printf("%d in ", convert_number_base(data->number, data->base, 10));
        printf("%d iteration(s) in base %d\n", data->iterations, data->base);
        exit(0);
    }
}

static void get_sum_number_base(data_t *data)
{
    data->number = convert_number_base(data->number, data->base, 10);
    data->number_rev = convert_number_base(data->number_rev, data->base, 10);
    data->number = data->number + data->number_rev;
    data->number = convert_number_base(data->number, 10, data->base);
}

static void calculate_reversed_number(data_t *data)
{
    if (data->str != NULL)
        free(data->str);
    data->str = my_itoa(data->number);
    if (data->reversed_str != NULL)
        free(data->reversed_str);
    data->reversed_str = strdup(data->str);
    my_strrev(data->reversed_str);
    data->number = atoi(data->str);
    data->number_rev = atoi(data->reversed_str);
}

void palindrome_n_option(data_t *data, int save_nbr)
{
    for (data->iterations = 1; data->iterations <= data->imax; data->iterations++) {
        data->number = convert_number_base(data->number, 10, data->base);
        calculate_reversed_number(data);
        get_sum_number_base(data);
        if (data->str != NULL)
            free(data->str);
        data->str = my_itoa(data->number);
        if (data->reversed_str != NULL)
            free(data->reversed_str);
        data->reversed_str = strdup(data->str);
        my_strrev(data->reversed_str);
        print_result(data, save_nbr);
        data->number = convert_number_base(data->number, data->base, 10);
    }
}
