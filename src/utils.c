#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
    int index_temp = 0;
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
    int nb_div = 1;

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
