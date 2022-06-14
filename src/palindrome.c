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

void palindrome(data_t *data)
{
    char *str = NULL;
    char *reversed_str = NULL;

    int number;
    int number_rev;

    while (data->iterations <= data->flags.imax) {
        number = convert_number_base(data->number, 10, data->flags.base);

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
        data->number = number;
    }
}
