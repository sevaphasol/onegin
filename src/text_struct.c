#include <stdlib.h>
#include "text_struct.h"

int text_validation(text_t* text)
{
    if (text->strings == NULL)
    {
        free(text->strings);
        free(text->addr);

        return DATA_INVALID;
    }

    if (text->addr == NULL)
    {
        free(text->strings);
        free(text->addr);

        return DATA_INVALID;
    }

    if (text->n_strings < 0)
    {
        return DATA_INVALID;
    }

    return DATA_VALID;
}
