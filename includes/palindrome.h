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
} data_t;

data_t *init_data(void);
void ini_flag(data_t *data, int argc, char **argv);

#endif
