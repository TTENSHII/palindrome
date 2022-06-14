//gfqsefesfse

#include "palindrome.h"

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL) exit(84);

    data->flags.base = 10;
    data->flags.imax = 100;
    data->flags.imin = 0;
    data->flags.n = false;
    data->flags.number = 0;
    data->flags.p = false;
    data->flags.h = false;
    data->iterations = 1;
    return (data);
}
