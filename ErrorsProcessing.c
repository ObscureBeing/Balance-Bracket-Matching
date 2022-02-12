/**************************************************************************
* Name: ErrorsProcessing.c                                                *
* Author: Muskan Vig                                                      *
* Date created: 23 October 2020                                           *
* date modified:                                                          *
* Purpose: It is the entry point for Balanced bracket checking program.   *
* It calls the required functions and executes the code.                  *
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileIO.h"
#include "Errors.h"

int main(int argc, char** argv)
{
    /*Validating commandd line arguments*/ 
    if(argc == 2) 
    {
        int i, j;
        char* filename;
        int issue = 1;

        /*Reserving space for 50 strings since we assume that file will not exceed 50 lines.*/
        char** array = calloc(50, sizeof(char*)); 

        filename = argv[1];

        /*Validating filename*/
        do 
        {
            fileStore(filename, array, &issue);

            if(issue == 1) 
            {
                printf("\nPlease enter correct file name.\n");
                fflush(stdout);
                scanf("%s", filename);
            }

        } while(issue == 1);

        for(i = 0; i < 50 && array[i] != NULL; i++) 
        {
            printf("%s\n", array[i]);
            array[i][strlen(array[i])-1] = '\0';
        }
   
        printf("\n");
        
        errors(array);

        /*Freeing each string, since each string was malloced*/
        for(j = 0; j <50; j++)
        { 
            free(array[j]);
            array[j] = NULL;
        }

        /*Now freeing the array*/
        free(array);
        array = NULL; 
   }
    else
        printf("Error: please check your command line arguments\n");

    return 0;
} /*Ends main*/
