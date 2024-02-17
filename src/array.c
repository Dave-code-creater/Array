// array.c

#include "array.h"

// Function to calculate the length of the array (excluding the INT_MIN terminator)
int* Length(int* array) {
    int* length_of_array = (int*)malloc(sizeof(int));

    int length = 0;
    while (array[length] != INT_MIN) {
        length++;
    }
    *length_of_array = length;

    return length_of_array;
}

// Function to create an empty array with INT_MIN as the terminator
int* Create_Array() {
    int* array = (int*)malloc(sizeof(int));
    *array = INT_MIN;

    return array;
}

// Function to insert a value into the array and update its length
int* Insert(int* initial, int* length, int value) {
    int* array = realloc(initial, ((*length) + 2) * sizeof(int));

    if (array == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    array[*length] = value;
    array[*length + 1] = INT_MIN; // Mark the end of the array
    (*length)++;                  // Increase the length

    return array;
}

// Function to print the array
void Read_Array(int* Array, int* Length) {
    printf("This is the array:\n");
    for (int i = 0; i <= *Length - 1; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

// Function to print the array in reverse order
void Read_Inverse_Array(int* Array, int* Length) {
    printf("This is an inverse array: \n");
    for (int i = *Length - 1; i >= 0; i--) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

// Function to calculate the sum of all elements in the array
int Sum_Of_All_Element(int* Array, int* Length) {
    int total = 0;
    for (int i = 0; i < *Length; i++) {
        total += Array[i];
    }
    return total;
}

// Function to create a copy of the array
int* Copy_Array(int* Array, int* Length) {
    int* Array_Copy = malloc(*Length * sizeof(int));

    if (Array_Copy == NULL) {
        free(Array_Copy);
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *Length; i++) {
        Array_Copy[i] = Array[i];
    }

    return Array_Copy;
}

// Function to count the number of duplicate numbers in the array
int Number_Of_Duplicate_Number(int* Array, int* Length) {
    int Number_of_duplicate_number = 0;
    for (int i = 0; i < *Length; i++) {
        for (int k = i + 1; k < *Length; k++) {
            if (Array[i] == Array[k]) {
                Number_of_duplicate_number++;
            }
        }
    }
    return Number_of_duplicate_number;
}

// Function to check if the array contains any duplicate elements
bool Contains_Duplicate_Element(int* nums, int* Length) {
    int Number_of_duplicate_number = Number_Of_Duplicate_Number(nums, Length);

    return Number_of_duplicate_number > 0;
}

// Function to concatenate the array with itself
int* Get_Concatenation(int* Array, int* Length) {
    int* Return_Array = malloc(*Length * 2 * sizeof(int));

    if (Return_Array == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *Length; i++) {
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