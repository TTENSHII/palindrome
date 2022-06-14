/*
** EPITECH PROJECT, 2022
** palindrome
** File description:
** main
*/

#include "palindrome.h"
#include <math.h>

int main(int argc, char **argv)
{
    data_t *data = NULL;

    data = init_data();
    ini_flag(data, argc, argv);
    if (data->flags.base < 2 || data->flags.base > 10) {
       data->flags.base = 10;
    }
    data->number = data->flags.number;
    palindrome(data);
    return (0);
}
