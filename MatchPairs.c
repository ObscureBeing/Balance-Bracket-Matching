/*******************************************************************
* Name: MatchPairs.c                                               *
* Author: Muskan Vig                                               *
* Date created: 23 October 2020                                    *
* date modified:                                                   *
* Purpose: Takes two brackets (opening and closing) and checks     *
* if both the brackets are a match i.e. opening and closing pair.  *
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "MatchPairs.h"

/***********************************************************
* Name: matchingPairs
* Imports: char open, char close
* Export: int match
* Purpose: Checks if both the brackets make a pair or not.
*************************************************************/

int matchingPairs(char open, char close)
{
    int match = 0;

    if(open == '(' && close == ')')
        match = 1;
    else if(open == '{' && close == '}')
        match = 1;
    else if(open == '<' && close == '>')
        match = 1;
    if(open == '[' && close == ']')
        match = 1;

    return match;
} /*End matchingPairs*/

