#!/usr/bin/env python3

import unittest
import cffi
import pathlib

# Define the C functions using cffi
ffi = cffi.FFI()
ffi.cdef("""
    int* Length(int* array);
    int* Create_Array();
    int* Insert(int* initial, int* length, int value);
    void Read_Array(int* Array, int* Length);
    void Read_Inverse_Array(int* Array, int* Length);
    int Sum_Of_All_Element(int* Array, int* Length);
    int* Copy_Array(int* Array, int* Length);
    int Number_Of_Duplicate_Number(int* Array, int* Length);
    bool Contains_Duplicate_Element(int* nums, int* Length);
    int* Get_Concatenation(int* Array, int* Length);
""")

# Load the C library
libpath = pathlib.Path().absolute() / "libs" / "libarray.so"
c_lib = ffi.dlopen(str(libpath))

# Load the C functions and return the array pointer and length pointer
def Load_Function():
    Array_Pointer = c_lib.Create_Array()
    Length_Array_Pointer = c_lib.Length(Array_Pointer)
    return Array_Pointer, Length_Array_Pointer
    
# Load the test case from a file and insert it into the array
def Load_Test_Case(test_case_1):
    length_test_case, test_case = Read_From_File(test_case_1)
    Array_Pointer, Length_Array_Pointer = Load_Function()
    for i in range(length_test_case):
        Array_Pointer = c_lib.Insert(Array_Pointer, Length_Array_Pointer, test_case[i])
    c_lib.Read_Array(Array_Pointer, Length_Array_Pointer)
    return Array_Pointer, Length_Array_Pointer

# Read the test case from a file and return the length and array
def Read_From_File(filename) -> list:
    with open(filename, "r") as file:
        length = int(file.readline())
        array = [int(file.readline()) for _ in range(length)]  
        return length, array 

# Check if the array pointer and length pointer have been initialized
def Check_Load_Function(Array_Pointer, Length_Array_Pointer, filename , test_answer, length):
    Status = ""
    assert isinstance(Array_Pointer, ffi.CData), "Array Pointer has not been initialized"
    print("Pointer to an array of integers has been initialized")

    assert isinstance(Length_Array_Pointer, ffi.CData), "Length Pointer has not been initialized"
    print("Length of array has been initialized")

    Array_Pointer, Length_Array_Pointer = Load_Test_Case(filename)
    Array_Pointer = list(ffi.unpack(Array_Pointer, Length_Array_Pointer[0]))
    
    try:
        assert Length_Array_Pointer[0] == length
        Status = "Pass"
    except AssertionError:
        print("Length of array is equal to 10")
        Status = "Fail"
    try:
        assert Array_Pointer == test_answer
        Status = "Pass"
    except AssertionError:
        print("Array Pointer has not been initialized")
        Status = "Fail"
    Length_Array_Pointer = int(ffi.cast("int", Length_Array_Pointer[0]))

    return Status, Array_Pointer, Length_Array_Pointer,filename

def Write_Log():
    with open("test/test_log.txt", "w") as file:
        for i in range(1, 11):
            filename = f"test/test_case_{i}.txt"
            length, test_answer = Read_From_File(filename)
            Array_Pointer, Length_Array_Pointer = Load_Function()
            status, Array_Pointer, Length_Array_Pointer, test_case = Check_Load_Function(Array_Pointer, Length_Array_Pointer, filename, test_answer, length)
            file.write(f"\nTest Case: {test_case}\n")
            file.write(f"Status: {status}\n")
            file.write(f"Array Pointer: {Array_Pointer}\n")
            file.write(f"Length Pointer: {Length_Array_Pointer}\n")



def Check():
    Array_Pointer, Length_Array_Pointer = Load_Test_Case("test/test_case_1.txt")
    Write_Log()
    
    


if __name__ == '__main__':
    Check()
    
