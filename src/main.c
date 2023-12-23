#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

int main(void)
{
    system("clear");

    printf("Hello World\n");

    int* arr = NULL;
    int length = Length_Of_Array();


    printf("The length of the array: %d\n",length);

    arr = Create_Array_3X3_Size();

    Print_3x3_Size(arr);
    
    free(arr);
    return 0;
}