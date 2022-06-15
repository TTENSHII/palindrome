/*
** EPITECH PROJECT, 2022
** palindrome
** File description:
** palindrome
*/

#ifndef PALINDROME_H_
    #define PALINDROME_H_
    #include <stddef.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>

typedef struct data_s {
    int n_flag;
    int p_flag;
    int h_flag;
    int imin;
    int imax;
    int base;
    int number;
    char *str;
    char *reversed_str;
    int iterations;
    int number_rev;
} data_t;

//-------INITIALISATION-------//
data_t *init_data(void);
void init_options_and_flags(data_t *data, int argc, char **argv);
void error_handler(data_t *data, int argc, char **argv);

//--------UTILS--------------//
int convert_number_base(int number, int from_base, int to_base);
char *my_strrev(char *str);
char *my_itoa(int nb);
void free_data(data_t *data);

//--------PALINDROME--------//
void palindrome_n_option(data_t *data, int save_nbr);
void palindrome_p_option(data_t *data, int save_nbr);

#endif
