#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#include "System_Functions.h"

/* Configurations */
#define LLEntry Student
#define LastElement 0
/* LinkedList */
typedef struct LINKEDLISTNODE{
    LLEntry data;
    struct LINKEDLISTNODE *Next;
    struct LINKEDLISTNODE *Previous;
}LLNode;

typedef struct LINKEDLIST{
    LLNode *top;
    int SIZE;
    int LastID;
}LinkedList;

void CreateLinkedList(LinkedList *Pll);
char LinkedListEmpty(LinkedList *Pll);
char LinkedListFull(LinkedList *Pll);
int LinkedListSize(LinkedList *Pll);
void ClearLinkedList(LinkedList *Pll);
void MoveUpSwapLL(LinkedList *Pll,int Position);
void MoveDownSwapLL(LinkedList *Pll, int Position);
void DublyRemoveLLNode(LLEntry *data,LinkedList *Pll, int Position);
void DublyAddLLNode(LLEntry data,LinkedList *Pll, int Position);
void DublyAddToTheLastLLNode(LLEntry data,LinkedList *Pll);
void DublyRemoveLLNodewithData(LLEntry *data,LinkedList *Pll);
void DublyCopyData(LLEntry *data,LinkedList *Pll,int Position);
void DublyReplaceData(LLEntry data,LinkedList *Pll, int Position);
LLNode* GetStudentNode(LinkedList *Pll);

#endif // DATASTRUCTURE_H_INCLUDED
