//array.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "array.h"



/**
 * Calculates the length of an array.
 *
 * @param array The input array.
 * @return A pointer to an integer representing the length of the array.
 */
int* Length(int* array)
{
    int* length_of_array = (int*)malloc(sizeof(int));

    int length = 0;
    while (array[length] != INT_MIN)
    {
        length++;
    }
    *length_of_array = length;

    return length_of_array;
}

/**
 * Creates an empty array.
 *
 * @return A pointer to the newly created array.
 */
int* Create_Array()
{
    int* array = (int*)malloc(sizeof(int));
    *array = INT_MIN; // Initialize with INT_MIN as the terminator

    return array;
}

/**
 * Inserts a value into an array.
 *
 * @param initial The initial array.
 * @param length The length of the initial array.
 * @param value The value to be inserted.
 * @return A pointer to the modified array.
 */
int* Insert(int* initial, int* length, int value)
{
    int* array = realloc(initial, ((*length) + 2) * sizeof(int));

    if (array == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    array[*length] = value;
    array[*length + 1] = INT_MIN; // Mark the end of the array
    (*length)++;                  // Increase the length

    return array;
}

/**
 * Prints the elements of an array.
 *
 * @param Array The array to be printed.
 * @param Length The length of the array.
 */
void Read_Array(int* Array, int* Length)
{

    printf("This is the array:\n");
    for (int i = 0; i <= *Length - 1; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

/**
 * Prints the elements of an array in reverse order.
 *
 * @param Array The array to be printed in reverse order.
 * @param Length The length of the array.
 */
void Read_Inverse_Array(int* Array, int* Length)
{
    printf("This is an inverse array: \n");
    for (int i = *Length - 1; i >= 0; i--)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

/**
 * Calculates the sum of all elements in an array.
 *
 * @param Array The input array.
 * @param Length The length of the array.
 * @return The sum of all elements in the array.
 */
int Sum_Of_All_Element(int* Array, int* Length)
{
    int total = 0;
    for (int i = 0; i < *Length; i++)
    {
        total += Array[i];
    }
    return total;
}

/**
 * Creates a copy of an array.
 *
 * @param Array The input array.
 * @param Length The length of the array.
 * @return A pointer to the copied array.
 */
int* Copy_Array(int* Array, int* Length)
{
    int* Array_Copy = malloc(*Length * sizeof(int)); // allocate memory for the array

    if (Array_Copy == NULL)
    {
        free(Array_Copy);
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *Length; i++)
    {
        Array_Copy[i] = Array[i];
    }

    return Array_Copy;
}

/**
 * Calculates the number of duplicate numbers in an array.
 *
 * @param Array The input array.
 * @param Length The length of the array.
 * @return The number of duplicate numbers in the array.
 */
int Number_Of_Duplicate_Number(int* Array, int* Length)
{
    int Number_of_duplicate_number = 0;
    for (int i = 0; i < *Length; i++)
    {
        for (int k = i + 1; k < *Length; k++) // Start from i+1 to avoid redundant comparisons
        {
            if (Array[i] == Array[k])
            {
                Number_of_duplicate_number++;
            }
        }
    }
    return Number_of_duplicate_number;
}

/**
 * Checks if an array contains duplicate elements.
 *
 * @param nums The input array.
 * @param Length The length of the array.
 * @return 1 if the array contains duplicate elements, 0 otherwise.
 */
bool Contains_Duplicate_Element(int* nums, int* Length)
{
    int Number_of_duplicate_number = Number_Of_Duplicate_Number(nums, Length);

    if (Number_of_duplicate_number > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Concatenates an array with itself.
 *
 * @param Array The input array.
 * @param Length The length of the array.
 * @return A pointer to the concatenated array.
 */
int* Get_Concatenation(int* Array, int* Length)
{
    int* Return_Array = malloc(*Length * 2 * sizeof(int));

    if (Return_Array == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *Length; i++)
    {
        Return_Array[i] = Return_Array[i + *Length] = Array[i];
    }

    return Return_Array;
}


// int* Create_Array_3X3_Size(void){

//     int Array[3][3];
//     for (int x = 0; x < 3; x++)
//     {
//         for (int y = 0; y < 3; y++)
//         {
//             printf("Input the value at the [%d][%d]: ", x, y);
//             scanf("%d", &Array[x][y]);
//         }
//     }

//     return Array;
// }

// void Print_3x3_Size(int* Array)
// {
//     for (int x = 0; x < 3; x++)
//     {
//         for (int y = 0; y < 3; y++)
//         {
//             printf("The value at the current index [%d][%d]: %d",x,y,Array[x][y]);
//         }
//     }
// }