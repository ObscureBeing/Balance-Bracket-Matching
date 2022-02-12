/**************************************************************************
* Name: Errors.c                                                          *
* Author: Muskan Vig                                                      *
* Date created: 21 October 2020                                           *
* date modified:                                                          *
* Purpose: Processes the multiple strings character by character          *
* and does the required operations for error handling and visualization.  *
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UpdateStrings.h"
#include "visualize.h"
#include "Errors.h"
#include "MatchPairs.h"
#include "BracketPair.h"

/*********************************************************************************************
* Name: errors
* Imports: array(char**)
* export: none
* Purpose: Processes strings character by character, checks for bracket mismatch errors 
* and calls working() for visualization accordingly.
************************************************************************************************/

void errors(char** array)
{
    int i, k, count;
    char ch;
    int error;
    char open;
    char temp;
    struct Bracket *bracket;
    struct Bracket *opening;
    struct Bracket *closing; 
    LinkedList* list = createLinkedList();
    
    k = 0;
    count = 0;
    i = 0;
    error = 0;
    open = ' ';
    temp = ' ';

    /*parse file, that, is process each line of file.
    We are checking for 50 lines since we can assume that file will noe exceed 50 lines*/

    for(i = 0; i < 50 && array[i] != NULL && error == 0; i++) 
    {
        count++;
        /*Processes each character in string*/
        for(k = 0; k < strlen(array[i]) && error == 0; k++) 
        {
            ch = array[i][k];

            switch(ch) 
            {
                case '(':
                case '[':
                case '{':
                case '<':

                temp = ch;

                bracket = malloc(sizeof(struct Bracket));

                bracket->row = i;
                bracket->col = k;
                bracket->ch = ch;
            
                /*Push opening bracket at top in LinkedList (stack)*/
                insertStart(list, bracket);
                
                /*Colors the string*/
                updateString(bracket, array, i, k);

                /*continues after coloured section of updated string*/
                k+= 11; 

                bracket = NULL;         
       
                /*break for switch case*/
                break;

                case ')':
                case ']':
                case '}':
                case '>':

                closing = malloc(sizeof(struct Bracket));
    
                closing->row = i;
                closing->col = k;
                closing->ch = ch;

                /*Error checking when list is empty and encountered a closing bracket (No opening bracket in list)*/               
                if(isEmpty(list) == 1) 
                {   error = 3;
                    open = return_bracket(ch);
                    updateString(closing, array, i, k); 
                    k--;               
                }            
                else 
                {
                    /*pop from stack (linked list head)*/
                    opening = (struct Bracket *) removeStart(list);                                      
                        
                    /*starting location to change string: array[i][k]. It updates opening bracket and highlights*/
                    updateString(closing, array, i, k);
                    k+= 11;

                    /*opening has starting index of code color*/
                    updateOpening(array, opening, ch);
 

                    /* Error checking for mismatch brackets (Closing bracket found is not a match for recent opening bracket*/
                    if(matchingPairs(opening->ch, ch) == 0) 
                    {
                        error = 1;
                        open = return_bracket(ch);

                    } 
                free(opening);
                opening = NULL;
               } /*Ends outer-if*/

                free(closing);
                closing = NULL;

                /*break for switch case
                continue after highlighted section of updated string*/
                break;
           
            } /*Ends switch*/
               
                /*print stack growing and shrinking
                CONDITIONALCOMPILING*/

                #ifdef STACK                
                if(k < strlen(array[i]))
                    workingList(array, i, k, list, error, open);
                else
                    workingList(array, i+1, k, list, error, open);   
                #endif     

                #ifndef STACK
                if(k < strlen(array[i]))
                    working(array, i, k, error, open);
                else
                    working(array, i+1, k, error, open);   
                #endif
       } /*Ends inner-for (character processing*/
        
    } /*Ends outer-for (line processing*/


    /*Checks error condition of bracket balance when it has reaced the End Of FIle
    and has not encountered closing bracket for most recent opening bracket (when list is not empty).*/
    if(isEmpty(list) == 0 && error == 0)
    {
        error = 2;
        open = return_bracket(temp);
        /*last row*/
        i = count-1;
        /*last index of last row */
        k = strlen(array[i])-1;

        /*print stack growing and shrinking
        CONDITIONALCOMPILING*/

        #ifdef STACK 
        workingList(array, i, k,list, error, open);
        #endif

        #ifndef STACK
        working(array, i, k, error, open);   
        #endif
    }

    /*No bracket balance error is there.*/
    if(error == 0)
        printf("\x1b[0;32mALL GOOD!\x1b[0m\n");

   
    freeLinkedList(list); 
   
    bracket = NULL;
    list = NULL;
    opening = NULL;
} /*Ends errors()*/

