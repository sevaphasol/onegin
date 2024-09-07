#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "input.h"
#include "data.h"
#include "output.h"

const bool REVERSED = true;

int main()
{
    FILE *file_ptr;
    file_ptr = fopen("data.txt", "rb");

    data_t data = {0};

    input(file_ptr, &data);

    fclose(file_ptr);

    printf("%s\n", data.strings);
    printf("%s\n", data.strings + 1);
    printf("%s\n", data.strings + 2);
    printf("%s\n", data.strings + 3);
    printf("%s\n", data.strings + 4);

    // bubble_sort(data);

    output(&data);

    return 0;
}
