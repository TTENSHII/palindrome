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
    if (data == NULL) return (84);
    init_options_and_flags(data, argc, argv);
    error_handler(data, argc, argv);

    if (data->p_flag == true) {
        palindrome_p_option(data, data->number);
    } else {
        palindrome_n_option(data, data->number);
    }
    free_data(data);
    return (0);
}
