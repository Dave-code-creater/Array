#include "Array/include/array.h"
#include "gtest/gtest.h"

TEST(ReadFromFile, ReadFromFile) {
    char file_name[] = "/home/dave/workstation/Array/data/test.txt";
    int* array = Create_Array();
    array = Read_From_File(array, file_name);
    int* length = Length(array);
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < *length; i++) {
        EXPECT_EQ(array[i], expected[i]);
    }
    free(array);
}