#include "palindrome.h"

void display_help(char *executable, data_t *data)
{
    printf("USAGE\n\t%s  -n number -p palindrome ", executable);
    printf("[-b base] [-imin i] [-imax i]\n");
    printf("\nDESCRIPTION\n");
    printf("\t-n n\tinteger to be transformed (>=0)\n");
    printf("\t-p pal\tpalindromic number to be obtained");
    printf(" (incompatible with the -n option) (>=0)\n");
    printf("if defined, all fitting values of n will be output\n");
    printf("\t-b base\tbase in which the procedure will be\n");
    printf("\texecuted (1<b<=10) [def: 10]\n");
    printf("\t-imin i\tminimum number of iterations, (>=0) [def: 0]\n");
    printf("\t-imax i\tmaximum number of iterations,, (>=0) [def: 100]\n");
    free_data(data);
    exit(0);
}

int convert_number_base(int number, int from_base, int to_base)
{
    int i = 0;
    int result = 0;
    int remainder = 0;

    while (number > 0) {
        remainder = number % to_base;
        result += remainder * pow(from_base, i);
        number /= to_base;
        i++;
    }
    return (result);
}

char *my_strrev(char *str)
{
    char temp = '\0';
    int len = strlen(str);

    if (str == NULL)
        return (NULL);
    for (int index = 0; index < len; index++) {
        temp = str[index];
        str[index] = str[len - 1];
        str[len - 1] = temp;
        len--;
    }
    return (str);
}

char *my_itoa(int nb)
{
    int nb_size = 1;

    for (int temp = nb; temp >= 10; temp = temp / 10)
        nb_size += 1;
    char *str = malloc(sizeof(char) * nb_size + 1);
    str[nb_size] = '\0';
    nb_size -= 1;
    while (nb_size >= 0) {
        str[nb_size] = nb % 10 + 48;
        nb = nb / 10;
        nb_size -= 1;
    }
    return (str);
}
