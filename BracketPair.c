/***************************************************************
* Name: BracketPair.c                                          *
* Author: Muskan Vig                                           *
* Date created: 21 October 2020                                *
* date modified:                                               *
* Purpose: Takes a bracket (opening or closing) and returns    *
* the matching (opening or closing) bracket as desired.        *
****************************************************************/

#include <stdio.h>
#include "BracketPair.h"

/***********************************************************************************
* Name: return_bracket
* Imports: ch(char)
* export: bracket(ch)
* Purpose: takes open or close bracket and returns matching bracket accordingly.
*************************************************************************************/

char return_bracket(char ch)
{
    char bracket;

    switch(ch)
    {
        case ')': bracket = '('; 
                  break;
        case '>': bracket = '<'; 
                  break;
        case '}': bracket = '{'; 
                  break;
        case ']': bracket = '['; 
                  break;
        case '(': bracket = ')'; 
                  break;
        case '<': bracket = '>'; 
                  break;
        case '{': bracket = '}'; 
                  break;
        case '[': bracket = ']'; 
                  break;    
    } /*Ends switch*/
    
    return bracket;
} /*Ends return_bracket*/
