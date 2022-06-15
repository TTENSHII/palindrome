#include "palindrome.h"

static void print_result(data_t *data, int save_nbr, int *found, char *compare_nb, int index)
{
    if (strcmp(data->str, compare_nb) == 0 && data->iterations >= data->imin) {
        printf("%d leads to %d ", index, save_nbr);
        printf("in %d interation(s) in base %d\n", data->iterations, data->base);
        *found = 1;
    }
}

static void loop_palindrome_p(data_t *data, int save_nbr, int *found, char *compare_nb, int index)
{
    for (data->iterations = 0; data->iterations <= data->imax; data->iterations++) {
        data->number = convert_number_base(data->number, 10, data->base);
        if (data->str != NULL)
            free(data->str);
        data->str = my_itoa(data->number);
        print_result(data, save_nbr, found, compare_nb, index);
        if (data->reversed_str != NULL)
            free(data->reversed_str);
        data->reversed_str = strdup(data->str);
        my_strrev(data->reversed_str);
        data->number = atoi(data->str);
        data->number_rev = atoi(data->reversed_str);
        data->number = convert_number_base(data->number, data->base, 10);
        data->number_rev = convert_number_base(data->number_rev, data->base, 10);
        data->number = data->number + data->number_rev;
    }
}

void palindrome_p_option(data_t *data, int save_nbr)
{
    int found = 0;
    int number_to_compare = convert_number_base(data->number, 10, data->base);
    char *str_to_compare = my_itoa(number_to_compare);
    data->number = save_nbr;

    for (int index = 0; index <= save_nbr; index++) {
        data->number = index;
        data->iterations = 0;
        loop_palindrome_p(data, save_nbr, &found, str_to_compare, index);
    }
    if (found == 0)
        printf("No solution found.\n");
    free(str_to_compare);
}
