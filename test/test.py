import unittest
import cffi
import pathlib

ffi = cffi.FFI()

def Load_DLL():
    libpaht = pathlib.Path().absolute()
    libpaht = str(libpaht / "libs" / "libarray.so") 
    c_lib = ffi.dlopen(libpaht)
    return c_lib

def Initialize_Array():
    c_lib = Load_DLL()
    Array_Pointer = c_lib.Create_Array()
    print(Array_Pointer)

if __name__ == '__main__':
    Initialize_Array()