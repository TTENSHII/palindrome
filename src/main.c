/*
** EPITECH PROJECT, 2022
** palindrome
** File description:
** main
*/

#include "palindrome.h"

int main(int argc, char **argv)
{
    data_t *data = NULL;

    data = init_data();
    ini_flag(data, argc, argv);
    printf("number=%d\n", data->flags.number);
    printf("base=%d\n", data->flags.base);
    printf("imin=%d\n", data->flags.imin);
    printf("imax=%d\n", data->flags.imax);
    printf("p=%d\n", data->flags.p);
    printf("n=%d\n", data->flags.n);
    printf("h=%d\n", data->flags.h);
    return (0);
}
