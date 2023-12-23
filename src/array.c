//array.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

int Length_Of_Array(void)
{
    int length_of_array;

    do {
        printf("How many elements do you want to have in the array? ");
        if (scanf("%d", &length_of_array) != 1) {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n'); // consume any remaining input
            length_of_array = -1; // set to invalid value to loop again
        }
    } while (length_of_array < 0);

    return length_of_array;
}

int* Create_Array(int Length)
{
    int* arr = malloc(Length * sizeof(int)); // allocate memory for the array

    if (arr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < Length; i++) {
        printf("Enter the value for element at position %d: ", i);
        scanf("%d", &arr[i]);
    }

    return arr;
}

void Read_Array(int* Array, int Length)
{
    printf("This is the array:\n");
    for (int i = 0; i < Length; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

void Read_Inverse_Array(int* Array, int Length)
{
    printf("This is an inverse array: ");
    for (int i = Length - 1; i >= 0; i--)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

int Sum_Of_All_Element(int* Array, int Length)
{
    int total = 0;
    for (int i = 0; i < Length; i++)
    {
        total += Array[i];
    }
    return total;
}

int* Copy_Array(int* Array, int Length)
{
    int* Array_Copy = malloc(Length * sizeof(int)); // allocate memory for the array

    if (Array_Copy == NULL) {
        free(Array_Copy);
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < Length; i++)
    {
        Array_Copy[i] = Array[i];
    }

    return Array_Copy;
}

int Number_Of_Duplicate_Number(int* Array, int Length)
{
    int Number_of_duplicate_number = 0;
    for (int i = 0; i < Length; i++)
    {
        for (int k = i + 1; k < Length; k++) // Start from i+1 to avoid redundant comparisons
        {
            if (Array[i] == Array[k])
            {
                Number_of_duplicate_number++;
            }
        }
    }
    return Number_of_duplicate_number;
}


// 0 - False 1 - True
bool Contains_Duplicate_Element(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Return value size * 2
int* Get_Concatenation(int* Array, int Length)
{
    int * Return_Array = malloc(Length * 2 * sizeof(int));

    if (Return_Array == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < Length; i++)
    {
        Return_Array[i] = Return_Array[i + Length] = Array[i];
    }

    return Return_Array;
}
int* Create_Array_3X3_Size(void){

    int Array[3][3];
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            printf("Input the value at the [%d][%d]: ", x, y);
            scanf("%d", &Array[x][y]);
        }
    }

    return Array;
}

void Print_3x3_Size(int* Array)
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            printf("The value at the current index [%d][%d]: %d",x,y,Array[x][y]);
        }
    }
}