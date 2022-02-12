/***************************************************************
* Name: visualize.c                                            *
* Author: Muskan Vig                                           *
* Date created: 24 October 2020                                *
* date modified:                                               *
* Purpose: it does the visualizing part, that is,              *
* it visualizes the basic bracket-matching algorithm.          *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "newSleep.h"
#include "LinkedList.h"
#include "visualize.h"

/***********************************************************************************************
* Name: working
* imports: array(char**), line(int), index(int), error(int), bracket(char)
* Export: none
* Purpose: Visualizes basic bracket-matching algorithm and outputs relevant error messages.
************************************************************************************************/

void working(char** array, int line, int index, int error, char bracket)
{
    int row, i;
    
    system("clear");
   
    for(row = 0; row < 50 && array[row] != NULL; row++) 
    {
        printf("%s\n", array[row]);
    
        if(row == line) 
        {
            for (i = 0; i <= index; i++)
            {
                if(array[row][i] == '\x1b')
                {
                    i += 11;
                    
                }/*End if*/
                
                putchar(' ');                            
            }/*End for*/
            printf("^ ");

            /*Displays relevant error messages according to the type of error parsed*/
            switch(error)
            {
                case 0:
                        break;
                case 1: printf("\x1b[0;46m\'%c\' expected\x1b[0m\n", bracket);
                        break;
                case 2: printf("\x1b[0;41m\'%c\' expected before End of Code\x1b[0m\n", bracket);
                        break;
                case 3: printf("\x1b[0;43m\'%c\' expected before this\x1b[0m\n", bracket);
                        break;           
            }/*End switch*/
            printf("\n");    
       }/*End outer-if*/           
    }/*End outer for*/

        newSleep(0.4);

} /*End working*/

/***********************************************************************************************
* Name: workingList
* imports: array(char**), line(int), index(int), LinkedList* list, error(int), bracket(char)
* Export: none
* Purpose: Visualizes basic bracket-matching algorithm and outputs relevant error messages.
* This method displays the list contents (stack's items) in conditional compiling.
*************************************************************************************************/

void workingList(char** array, int line, int index, LinkedList* list, int error, char bracket)
{
    int row, i;
    
    system("clear");

    /*Prints out stack (list) and shows the insertion and removal of brackets*/
    printf("STACK: \n");
    printf("Linked List (Brackets): List grows on encountering opening bracket and shrinks on encountering closing bracket.\n");
    printf("-------------\n");
    printLinkedList(list, *printBracket);
    printf("-------------\n");
  
    for(row = 0; row < 50 && array[row] != NULL; row++) 
    {
        printf("%s\n", array[row]);

        if(row == line) 
        {
            for (i = 0; i <= index; i++)
            {
                if(array[row][i] == '\x1b')
                {
                    i += 11;
                    
                }/*End if*/
                
                putchar(' ');                            
            }/*End for*/
        printf("^ ");

        /*Displays relevant error messages according to the type of error parsed*/
        switch(error)
        {
            case 0:
                    break;
            case 1: printf("\x1b[0;46m\'%c\' expected\x1b[0m\n", bracket);
                    break;
            case 2: printf("\x1b[0;41m\'%c\' expected before End of Code\x1b[0m\n", bracket);
                    break;
            case 3: printf("\x1b[0;43m\'%c\' expected before this\x1b[0m\n", bracket);
                    break;           
        }/*End switch*/
            printf("\n");    
       }/*End outer-if*/           
    }/*End outer-for*/

        newSleep(0.4);
} /*End workingList*/

