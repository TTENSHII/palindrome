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
    init_options(data, argc, argv);
    error_handler(data, argc, argv);
    palindrome(data);
    return (0);
}
