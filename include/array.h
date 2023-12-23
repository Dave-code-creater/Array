/* array.h */

#ifndef MY_HEADER_H__
#define MY_HEADER_H__

// Create an return the address of the array as a pointer
extern int Length_Of_Array();
extern int* Create_Array(int Length);
extern void Read_Array(int* Array, int Length);
extern void Read_Inverse_Array(int* Array, int Length);
extern int Sum_Of_All_Element(int* Array, int Length);
extern int* Copy_Array(int* Array, int Length);
extern bool Contains_Duplicate_Element(int* Array, int Length);
extern int* Get_Concatenation(int* Array, int Length);
extern int* Create_Array_3X3_Size(void);
extern void Print_3x3_Size(int* Array);
extern int RemoveDuplicates(int* Array, int Length);
#endif