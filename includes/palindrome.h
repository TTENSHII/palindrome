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

typedef struct flag_s {
    int n;
    int p;
    int h;
    int imin;
    int imax;
    int number;
    int base;
} flag_t;

typedef struct data_s {
    flag_t flags;
    int number;
    int reversed_number;
    int iterations;
} data_t;

data_t *init_data(void);
void palindrome(data_t *data);
void ini_flag(data_t *data, int argc, char **argv);

char *my_strrev(char *str);
char *my_itoa(int nb);

int convert_number_base(int number, int from_base, int to_base);

#endif
