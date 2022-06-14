#include "palindrome.h"

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    if (data == NULL) exit(84);

    data->base = 10;
    data->h_flag = false;
    data->imax = 100;
    data->imin = 0;
    data->n_flag = false;
    data->number = 0;
    data->p_flag = false;
    return (data);
}
