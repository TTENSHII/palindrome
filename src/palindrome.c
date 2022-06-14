#include <palindrome.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int convert_number_base(int number, int from_base, int to_base)
{
    int result = 0;
    int remainder = 0;
    int i = 0;

    while (number > 0) {
        remainder = number % to_base;
        result += remainder * pow(from_base, i);
        number /= to_base;
        i++;
    }
    return (result);
}

void p_option(data_t *data)
{
    char *str = NULL;
    char *reversed_str = NULL;
    int found = 0;


    char *to_compare = my_itoa(data->flags.number);

    int number;
    int number_rev;

    number = data->number;

    for (int i = 0; i <= data->number; i++) {
        number = i;
        data->iterations = 0;
        while (data->iterations <= data->flags.imax) {
            number = convert_number_base(number, 10, data->flags.base);
            str = my_itoa(number);
            if (strcmp(str, to_compare) == 0 && data->iterations >= data->flags.imin) {
                printf("%d leads to %d in %d interation(s) in base %d\n", i, data->flags.number, data->iterations, data->flags.base);
                found = 1;
            }
            reversed_str = strdup(str);
            my_strrev(reversed_str);

            number = atoi(str);
            number_rev = atoi(reversed_str);

            number = convert_number_base(number, data->flags.base, 10);
            number_rev = convert_number_base(number_rev, data->flags.base, 10);
            number = number + number_rev;

            data->iterations++;
        }
    }
    if (found == 0) {
        printf("No solution found.\n");
    }
}

void palindrome(data_t *data)
{

    if (data->flags.p == true) {
        p_option(data);
        exit(0);
    }
    char *str = NULL;
    char *reversed_str = NULL;

    int number;
    int number_rev;

    number = data->number;
    while (data->iterations <= data->flags.imax) {
        number = convert_number_base(number, 10, data->flags.base);

        str = my_itoa(number);
        reversed_str = strdup(str);
        my_strrev(reversed_str);

        number = atoi(str);
        number_rev = atoi(reversed_str);

        number = convert_number_base(number, data->flags.base, 10);
        number_rev = convert_number_base(number_rev, data->flags.base, 10);

        number = number + number_rev;

        number = convert_number_base(number, 10, data->flags.base);
    
        str = my_itoa(number);
        reversed_str = strdup(str);
        my_strrev(reversed_str);
        
        if (strcmp(str, reversed_str) == 0) {
            printf("%d leads to %d in %d interation(s) in base %d\n", data->flags.number, convert_number_base(number, data->flags.base, 10), data->iterations, data->flags.base);
            exit(0);
        }
        data->iterations++;
        number = convert_number_base(number, data->flags.base, 10);
    }
}
