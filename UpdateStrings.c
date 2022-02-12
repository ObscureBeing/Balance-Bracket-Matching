/********************************************************************************************************************
* Name: UpdateStrings.c                                                                                             *
* Author: Muskan Vig                                                                                                *
* Date created: 24 October 2020                                                                                     *
* date modified:                                                                                                    *
* Purpose: It manipulates strings in array of strings.                                                              *
* It embeds colours for opening brackets and higlights for closing. However, on encountering closing bracket,       *
* it highlights matching open brackets previously encountered (Updates opening brackets).                           *
*********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Substrings.h"
#include "LinkedList.h"
#include "UpdateStrings.h"

/*********************************************************************************************************
* Name: updateString
* imports: bracket(struct Bracket*), array(char**), i(int), k(int)
* Export: none
* Purpose: Updates the string of array with colours according to the type of bracket (open or close).
***********************************************************************************************************/

void updateString(struct Bracket* bracket, char** array, int i, int k) 
{ 
    char* temp;

    char* strBefore = calloc(300, sizeof(char*));
    char middle[13];
    char* strAfter = calloc(300, sizeof(char*));
    char* str = calloc(300, sizeof(char*));

    switch(bracket->ch) 
    {   
        /*updates bracket inside switch*/
        case '(': strcpy(middle, "\x1b[0;33m(\x1b[0m"); 
                  break;
        case ')': strcpy(middle, "\x1b[0;43m)\x1b[0m"); 
                  break;
        case '{': strcpy(middle, "\x1b[0;31m{\x1b[0m"); 
                  break;
        case '}': strcpy(middle, "\x1b[0;41m}\x1b[0m"); 
                  break;
        case '[': strcpy(middle, "\x1b[0;36m[\x1b[0m"); 
                  break;
        case ']': strcpy(middle, "\x1b[0;46m]\x1b[0m"); 
                  break;
        case '<': strcpy(middle, "\x1b[0;35m<\x1b[0m"); 
                  break;
        case '>': strcpy(middle, "\x1b[0;45m>\x1b[0m"); 
                  break;
    }/*End switch*/

    temp = my_substr(array[i], 0, k);
    strcpy(strBefore, temp);
    free(temp);
    temp = my_substr2(array[i], k+1);
    strcpy(strAfter, temp); 
    free(temp);
    temp = NULL;

    strcat(str, strBefore);
    strcat(str, middle);
    strcat(str, strAfter);
    strcpy(array[i], str);

    free(strBefore);
    free(strAfter);
    free(str);

    strBefore = NULL;
    strAfter = NULL;
    str = NULL;

}/*End updateString*/

/***************************************************************************************
* Name: updateopening
* imports: array(char**), opening(struct Bracket*), ch(char)
* Export: none
* Purpose: Updates the string of array (highlights opening bracket), embeds colours
* after encountering matching closing bracket.
*****************************************************************************************/

void updateOpening(char** array,struct Bracket* opening, char ch)
{
    int i, k;
    char* temp;

    char* strBefore = calloc(300, sizeof(char*));
    char middle[13];
    char* strAfter = calloc(300, sizeof(char*));
    char* str = calloc(300, sizeof(char*));

    i = opening->row;
    k = opening->col;

    switch(opening->ch) 
    {  
        /*updates values*/
        case '(': strcpy(middle, "\x1b[0;43m(\x1b[0m"); 
                  break;
        case '{': strcpy(middle, "\x1b[0;41m{\x1b[0m"); 
                  break;
        case '[': strcpy(middle, "\x1b[0;46m[\x1b[0m"); 
                  break;
        case '<': strcpy(middle, "\x1b[0;45m<\x1b[0m"); 
                  break;
   }/*end switch*/

    temp = my_substr(array[i], 0, k);
    strcpy(strBefore, temp);
    free(temp);
    temp = my_substr2(array[i], k+12);
    strcpy(strAfter, temp);
    free(temp);
    temp = NULL;

    strcat(str, strBefore);
    strcat(str, middle);
    strcat(str, strAfter);
    strcpy(array[i], str);

    free(strBefore);
    free(strAfter);
    free(str); 
    strBefore = NULL;
    strAfter = NULL;
    str = NULL;

}/*End updateOpening*/



