#ifndef MY_HEADER_H__
#define MY_HEADER_H__

// Include the standard library.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <limits.h>
#include "array.h"
#include <time.h>


extern char file_name[255];
extern char buffer[255];

// Creates an empty array.
// Returns a pointer to the newly created array.
int* Create_Array();

// Inserts a value into an array.
// Parameters:
//   - initial: The initial array.
//   - Length: The length of the initial array.
//   - value: The value to be inserted.
// Returns a pointer to the modified array.
int* Insert(int* inital, int* Length, int value);

// Calculates the length of an array.
// Parameters:
//   - Array: The input array.
// Returns a pointer to an integer representing the length of the array.
int* Length(int* Array);

// Prints the elements of an array.
// Parameters:
//   - Array: The array to be printed.
//   - Length: The length of the array.
void Read_Array(int* Array, int* Length);

// Prints the elements of an array in reverse order.
// Parameters:
//   - Array: The array to be printed in reverse order.
//   - Length: The length of the array.
void Read_Inverse_Array(int* Array, int* Length);

// Calculates the sum of all elements in an array.
// Parameters:
//   - Array: The input array.
//   - Length: The length of the array.
// Returns the sum of all elements in the array.
int Sum_Of_All_Element(int* Array, int* Length);

// Creates a copy of an array.
// Parameters:
//   - Array: The input array.
//   - Length: The length of the array.
// Returns a pointer to the copied array.
int* Copy_Array(int* Array, int* Length);

// Calculates the number of duplicate numbers in an array.
// Parameters:
//   - Array: The input array.
//   - Length: The length of the array.
// Returns the number of duplicate numbers in the array.
int Number_Of_Duplicate_Number(int* Array, int* Length);

// Checks if an array contains duplicate elements.
// Parameters:
//   - nums: The input array.
//   - Length: The length of the array.
// Returns 1 if the array contains duplicate elements, 0 otherwise.
bool Contains_Duplicate_Element(int* Array, int* Length);

// Concatenates an array with itself.
// Parameters:
//   - Array: The input array.
//   - Length: The length of the array.
// Returns a pointer to the concatenated array.
int* Get_Concatenation(int* Array, int* Length);

int* Create_Array_3X3_Size(void);
void Print_3x3_Size(int* Array);
int RemoveDuplicates(int* Array, int Length);

int* Read_From_File(int* array,const char* file_name);

#endif  // MY_HEADER_H__
