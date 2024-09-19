#include <stdlib.h>
#include "text_struct.h"

int text_validation(text_t* text)
{
    if (text == NULL)
    {
        printf("%d", __LINE__);
        return TEXT_INVALID;
    }

    if (text->struct_strings == NULL)
    {
        printf("%d", __LINE__);
        return TEXT_INVALID;
    }

    if (text->strings == NULL)
    {
        printf("%d", __LINE__);
        return TEXT_INVALID;
    }

    if (text->addr == NULL)
    {
        printf("%d", __LINE__);
        return TEXT_INVALID;
    }

    if (text->file_ptr == NULL)
    {
        printf("%d", __LINE__);
        return TEXT_INVALID;
    }

    return TEXT_VALID;
}

void text_free(text_t* text)
{
    free(text->strings);

    // free(text->struct_strings);

    // free(text->addr);
}
