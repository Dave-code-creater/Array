import unittest
import cffi
import pathlib

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
libpaht = pathlib.Path().absolute()
libpaht = str(libpaht / "libs" / "libarray.so") 
c_lib = ffi.dlopen(libpaht)



def Load_Function():
    Array_Pointer = ffi.new("int *")
    Array_Pointer = c_lib.Create_Array()
    Length_Array_Pointer = ffi.new("int *")
    Length_Array_Pointer = c_lib.Length(Array_Pointer)
    return Array_Pointer, Length_Array_Pointer
    
def Load_Test_Case(test_case_1):
    length_test_case,test_case = Read_From_File(test_case_1)
    Array_Pointer, Length_Array_Pointer = Load_Function()
    for i in range(length_test_case):
        Array_Pointer = c_lib.Insert(Array_Pointer, Length_Array_Pointer, test_case[i])
    c_lib.Read_Array(Array_Pointer, Length_Array_Pointer)

def Read_From_File(filename) -> list:
    with open(filename, "r") as file:
        length = int(file.readline())
        array = [int(file.readline()) for x in range(length)]  
        return length, array 

if __name__ == '__main__':
    Load_Test_Case("test/test_case_1.txt")
