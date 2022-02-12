/***********************************************************************************
* Name: FileIO.c                                                                   *
* Author: Muskan Vig                                                               *
* Date created: 23 October 2020                                                    *
* date modified:                                                                   *
* Purpose: It reads the file line by line and stores it in an array of strings     *
* for further manipulation.                                                        *
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileIO.h"

/***********************************************************************************
* Name: fileStore
* imports: char* filename, char** array
* Export: char** array
* Purpose: It reads file line by line and stores them in array of strings for
*  further processing and manipulation.
*************************************************************************************/

char** fileStore(char* filename, char** array, int* issue)
{
    int i;

    char** array2 = array;
    char str[INPUT_SIZE];

    FILE *inFile = fopen(filename, "r");

    i = 0;

    if(inFile == NULL)                         
    {
        perror("Error opening file");
    }
    else 
    {     
        printf("Process file: %s", filename);

        while(fgets(str, INPUT_SIZE, inFile)) 
        {
            *array2 = calloc(strlen(str) + 1, sizeof(char*));
            strcpy(*array2, str);
            array2++;
            i++;
       }
            
        *issue = 0;
        fclose(inFile);
 
   }
    return array;
} /*End fileStore*/

