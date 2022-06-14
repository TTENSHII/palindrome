#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strrev(char *str)
{
    int len = strlen(str);
    char temp = '\0';
    int index_temp = 0;

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

char *my_itoa(unsigned long int nb)
{
    int nb_size = 1;
    unsigned long int nb_div = 1;

    for (unsigned long int temp = nb; temp >= 10; temp = temp / 10)
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
