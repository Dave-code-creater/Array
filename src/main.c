#include "array.h"

int main(void)
{
    system("clear");

    printf("Hello World\n");

    char file_name[] = "/home/dave/workstation/Array/data/test.txt";
    int* array = Create_Array();
    array = Read_From_File(array, file_name);
    int* length = Length(array);

    Read_Array(array, length);

    // bool contains_duplicate = Contains_Duplicate_Element(array, length);
    // printf("Contains duplicate: %s\n", contains_duplicate ? "true" : "false");

    free(array);
    return 0;
}