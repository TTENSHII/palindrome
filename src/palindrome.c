#include <palindrome.h>

void p_option(data_t *data)
{
    char *str = NULL;
    char *reversed_str = NULL;
    int found = 0;
    int iterations = 0;

    int nb_aaaa = convert_number_base(data->number, 10, data->base);
    char *to_compare = my_itoa(nb_aaaa);

    int number;
    int number_rev;

    number = data->number;

    for (int i = 0; i <= data->number; i++) {
        number = i;
        iterations = 0;
        while (iterations <= data->imax) {
            number = convert_number_base(number, 10, data->base);
            str = my_itoa(number);
            if (strcmp(str, to_compare) == 0 && iterations >= data->imin) {
                printf("%d leads to %d in %d interation(s) in base %d\n", i, data->number, iterations, data->base);
                found = 1;
            }
            reversed_str = strdup(str);
            my_strrev(reversed_str);

            number = atoi(str);
            number_rev = atoi(reversed_str);

            number = convert_number_base(number, data->base, 10);
            number_rev = convert_number_base(number_rev, data->base, 10);
            number = number + number_rev;
            iterations++;
        }
    }
    if (found == 0) {
        printf("No solution found.\n");
    }
}

void palindrome(data_t *data)
{

    if (data->p_flag == true) {
        p_option(data);
        exit(0);
    }
    char *str = NULL;
    char *reversed_str = NULL;
    int iterations = 1;
    int number;
    int number_rev;

    number = data->number;
    while (iterations <= data->imax) {
        number = convert_number_base(number, 10, data->base);

        str = my_itoa(number);
        reversed_str = strdup(str);
        my_strrev(reversed_str);

        number = atoi(str);
        number_rev = atoi(reversed_str);

        number = convert_number_base(number, data->base, 10);
        number_rev = convert_number_base(number_rev, data->base, 10);

        number = number + number_rev;

        number = convert_number_base(number, 10, data->base);
    
        str = my_itoa(number);
        reversed_str = strdup(str);
        my_strrev(reversed_str);
    
        if (strcmp(str, reversed_str) == 0) {
            printf("%d leads to %d in %d interation(s) in base %d\n", data->number, convert_number_base(number, data->base, 10), iterations, data->base);
            exit(0);
        }
        iterations++;
        number = convert_number_base(number, data->base, 10);
    }
}
