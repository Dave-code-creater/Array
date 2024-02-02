#include "array.h"

int* Read_The_Size_File(char* file_name) {
    char* buffer_size = (char*)malloc(sizeof(char));
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%[^\n]", buffer_size);
    int* length = (int*)malloc(sizeof(int));
    *length = atoi(buffer_size);

    fclose(file);
    return length;
}

int* Read_Content_From_File(int* array,const char* file_name, int* length) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(EXIT_FAILURE);
    }
    // Skip the first line
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);

    array = (int*)malloc((*length + 1) * sizeof(int));
    for (int i = 0; i < *length; i++) {
        fscanf(file, "%d", &array[i]);
    }
    array[*length] = INT_MIN;
    fclose(file);
    return array;
}

int* Read_From_File(int* array,const char* file_name) {
    int* length = Read_The_Size_File(file_name);
    array = Read_Content_From_File(array, file_name, length);
    return array;
}

void Write_Additional_Information(const char* file_name)
{
    ;
}