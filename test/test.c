#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(void)
{
    FILE* fptr = fopen("test_case_1.txt", "r");
    int* test = Create_Array();

    if (fptr == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char buffer[sizeof(int)];

    int* Length = fgets(buffer, sizeof(buffer), fptr);

    for (int i = 0 ; i < *Length; i++)
    {
        test = Insert(test, Length, fgets(buffer, sizeof(buffer), fptr));
    }

    Read_Array(test, Length);

    fclose(fptr);
    free(test);


    int* test = Create_Array();




}