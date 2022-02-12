/********************************************************************
* Name: LinkedList.c                                                *
* Author: Muskan Vig                                                *
* Date created: 20 October 2020                                     *
* date modified:                                                    *
* Purpose: It is a GENERIC DOUBLE-ENDED DOUBLY LINKED LIST.         *
* It is a data structure used to check for balanced bracket here.   *
*********************************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include "LinkedList.h"

/****************************************************************************
* Name: createLinkedList
* Imports: none
* Export: LinkedList* list
* Purpose: Creates a list and points its head and tail to null initially.
******************************************************************************/

LinkedList* createLinkedList()
{
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;

    return list;
} /*Ends createLinekedList()*/

/*******************************************************
* Name: insertStart
* Imports: LinkedList* list, void* entry
* Export: none
* Purpose: Inserts data at the start of the list.
*******************************************************/

void insertStart(LinkedList* list, void* entry)
{
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = entry;
    newNode->next = list->head;
    newNode->prev = NULL;
    list->head = newNode;

    if(list->tail == NULL)
    {
        list-> tail = newNode;
    }
} /*End insertStart()*/

/*****************************************************************************************
* Name: removeStart
* Imports: LinkedList* list
* Export: void* value
* Purpose: It removes the item from the start of the list and returns the item removed.
******************************************************************************************/

void* removeStart(LinkedList* list)
{ 
    void* value;
    LinkedListNode* temp = list->head;
    value = list->head->data;
    list->head = list->head->next;
    free(temp);
    return(value);
} /*End insertStart()*/

/******************************************************
* Name: insertLast
* Imports: LinkedList* list, void* entry
* Export: none
* Purpose: It inserts item at th end of the list.
*******************************************************/

void insertLast(LinkedList* list, void* entry)
{
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    newNode->data = entry;
    newNode->next = NULL;

    if(list->tail == NULL)
    {
        newNode->prev = list->tail;
        list->tail = newNode;
        list->head = newNode;
    }
   else
    {
        newNode->prev = list->tail;
        newNode->prev->next = newNode;
        list->tail = newNode;
    }
} /*End insertLast()*/

/***************************************************************************************
* Name: removeLast()
* Imports: LinkedList* list
* Export: void* value
* Purpose: It removes item from the last of the list and returns the removed item.
****************************************************************************************/

void* removeLast(LinkedList* list)
{
    void* value;
    LinkedListNode* temp = list->tail;
    value = list->tail->data;
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(temp);

    return(value);
}/*End removeStart()*/

/***********************************************************************************************************************
* Name: printLinkedList
* Imports: *LinkedList* list, listFunc funcptr
* Export: none
* Purpose: It takes in function pointer which helps in typecasting and printing items of Generic linked list.
*************************************************************************************************************************/

void printLinkedList(LinkedList* list, listFunc funcPtr)
{
    LinkedListNode* current = list->head;

    while(current != NULL) 
    {         
        (*funcPtr)(current->data);
        current = current->next;
    }

    printf("\n");
} /*End printLinkedList()*/

/******************************************************************************
* Name: printInt
* Imports: void* data
* Export: none
* Purpose: Typecasts the void*, generic data to integer and prints it out.
*******************************************************************************/

void printInt(void* data)
{
    int* a = (int*)data;
    printf("%d\n", *a);
}/*End printInt*/

/************************************************************************
* Name: printFloat
* Imports: void* data
* Export: none
* Purpose: Typecasts the void*, generic data to float and prints it out.
**************************************************************************/

void printFloat(void* data)
{
    float* a = (float*)data;
    printf("%f\n", *a);
} /*End printFloat*/

/*****************************************************************************
* Name: printChar
* Imports: void* data
* Export: none
* Purpose: Typecasts the void*, generic data to character and prints it out.
*******************************************************************************/

void printChar(void* data)
{
    char* a = (char*)data;
    printf("%c\n", *a);
}/*End printChar*/

/******************************************************************************
* Name: printBracket
* Imports: void* data
* Export: none
* Purpose: typecasts void* to struct and prints out field member of struct.
******************************************************************************/

void printBracket(void* data) 
{
    struct Bracket* bracket = (struct Bracket*)data;
    char ch = bracket->ch;
    printf("%c\n", ch);
}/*End printBracket*/

/***********************************************************************
* Name: isEmpty()
* Imports: LinkedList* list
* Export: int empty
* Purpose: Checks if Linked list is empty or not.
*************************************************************/

int isEmpty(LinkedList* list)
{
    int empty;
    empty = 0;

    if(list->head == NULL)
        empty = 1;

    return empty;
} /*End isEmpty*/

/************************************************************************
* Name: freeLinkedList
* Imports: LinkedList* list
* Export: none
* Purpose: Frees each node of the list and then at last frees the list.
**************************************************************************/

void freeLinkedList(LinkedList* list)
{
    LinkedListNode *node, *nextNode;
    node = list->head;

    while(node != NULL) 
    {
        nextNode = node->next;
        free(node->data);
        node->data = NULL;
        free(node);
        node = nextNode;
    }

    free(list);
} /*End freeLinkedList*/
