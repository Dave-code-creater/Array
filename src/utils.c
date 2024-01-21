#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include "array.h"



void Read_From_File(int* array,char* name)
{
    struct dirent * de;  // Pointer for directory entry
    DIR *dr;

    dr = opendir("./data");

    if (dr == NULL)
    {
        printf("Error: Directory not found\n");
        exit(EXIT_FAILURE);
    }

    FILE* file_pointer = fopen(name, "r"); 
    if (file_pointer == NULL)
    {
        printf("Error: File not found\n");
        exit(EXIT_FAILURE);
    }
    // Read the first line of the file

    char buffer[255];
    fgets(buffer, 60, file_pointer);
    
    while ((de = readdir(dr)) != NULL)
    {
        while(fgets(buffer, 60, file_pointer)!=NULL )
        {
            array = Insert(array, buffer, atoi(buffer));
        }
    }
    fclose(file_pointer);
    closedir(dr);
}