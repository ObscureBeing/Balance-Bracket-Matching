/***************************************************************
* Name: Substrings.c                                           *
* Author: Muskan Vig                                           *
* Date created: 22 October 2020                                *
* date modified:                                               *
* Purpose: Methods in this file perofrms substr() operations.  * 
* (Custom implementation)                                      *
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Substrings.h"

/**************************************************************************************************
* Name: my_suvstr
* imports: char* str, int start, int len
* Export: char* temp
* Purpose: This method returns substring of imported string of length 'len' from index 'start'.
***************************************************************************************************/

char* my_substr(char* str, int start, int len) 
{    
    char* temp = malloc(sizeof(char*) * (len + 1));
    int i;
    
    for(i = 0; i < len; i++) 
    {
        temp[i] = str[start+i];
    }

    temp[len] = '\0';
    return temp;
} /*end my_substr*/

/************************************************************************************
* Name: my_substr2
* imports: str(char*), start(int)
* Export: temp(char*)
* Purpose: This method returns substring of imported string from 'start' index 
* till length of imported string.
**************************************************************************************/

char* my_substr2(char* str, int start)
{
    return my_substr(str, start, strlen(str)-start);
} /*end my_substr2*/


