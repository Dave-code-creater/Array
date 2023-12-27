#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

int main(void)
{
    system("clear");

    printf("Hello World\n");


    int* length = (int*)malloc(sizeof(int));
    *length = 0;

    int* array = Create_Array();

    array = Insert(array, length, 1);
    array = Insert(array, length, 2);
    array = Insert(array, length, 3);
    array = Insert(array, length, 4);
    array = Insert(array, length, 5);
    array = Insert(array, length, 6);
    array = Insert(array, length, 1);

    length = Length(array);

    bool contains_duplicate = Contains_Duplicate_Element(array, length);
    printf("Contains duplicate: %s\n", contains_duplicate ? "true" : "false");
    
    free(array);
    return 0;
}