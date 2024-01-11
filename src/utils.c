#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include "array.h"



extern void Read_From_File(int* array,int* Length,char* name)
{
    struct dirent * de;  // Pointer for directory entry
    DIR *dr;

    if (dr = opendir("data") == NULL)
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
    while ((de = readdir(dr)) != NULL)
    {
        while(fgets(buffer, 60, file_pointer)!=NULL )
        {
            array = Insert(array, Length, atoi(buffer));
        }
    }
            
}