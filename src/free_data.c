#include "palindrome.h"

void free_data(data_t *data)
{
    if (data == NULL)
        return;
    if (data->str != NULL)
        free(data->str);
    if (data->reversed_str != NULL)
        free(data->reversed_str);
    free(data);
}
