#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Bracket 
{
    int row;   
    int col;
    char ch;
};

typedef struct LinkedListNode 
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;

} LinkedListNode; 

typedef struct 
{
    LinkedListNode* head;
    LinkedListNode* tail;

} LinkedList;


LinkedList* createLinkedList(); 
void insertStart(LinkedList* list, void* entry);
void* removeStart(LinkedList* list);
void insertLast(LinkedList* list, void* entry);
void* removeLast(LinkedList* list);
void freeLinkedList(LinkedList* list);
typedef void (*listFunc)(void* data);
void printInt(void* data);
void printFloat(void* data);
void printChar(void* data);
void printBracket(void* data);

int isEmpty(LinkedList* list);
void printLinkedList(LinkedList* list, listFunc funcPtr);

#endif
