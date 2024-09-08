#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // bubble_sort(&data, &strcmp);

    output(&data);

    return 0;
}
