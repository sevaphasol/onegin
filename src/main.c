#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

const bool REVERSED = true;

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "r");

    data_t data = {.height = HEIGHT, .maxlength = MAXLINE};

    for (int i = 0; i < HEIGHT; i++)
    {
        fgets(data.strings[i], data.maxlength, fp);
        data.index[i] = i;
    }

    fclose(fp);

    bubble_sort(&data);

    for (int i = 0; i < HEIGHT; i++)
        printf("%s", data.strings[data.index[i]]);

    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
        printf("%d \n", data.index[i]);

    // for (int i = 0; i < HEIGHT; i++)
    //     printf("%d\n", data.index[i]);

    // char str1[] = "fdcba";
    // char str2[] = "edcba";

    // printf("%d\n", my_strcmp(str1, str2, REVERSED));

    // printf("%ld\n", my_size_of("123\0\0\0"));
    return 0;
}
