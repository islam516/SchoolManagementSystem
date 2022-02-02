#include <Stdio.h>
#include <stdlib.h>
#include "DublyLinkedList.h"

void CreateLinkedList(LinkedList *Pll)
{   /* Function to initialize the size and create the LinkedList*/
    Pll->top = NULL;    //initialize top pointer with NULL
    Pll->SIZE = 0;      //Initialize Size with 0 Nodes
    Pll->LastID = 221000;    //Initialize the last ID with 0;
}

void DublyAddLLNode(LLEntry data,LinkedList *Pll, int Position)
{   //Add node with position
    LLNode *Pn = (LLNode *)malloc(sizeof(LLNode));  //Memory Allocate with Size of the LinkedList Node
    LLNode *P1 = Pll->top;                          //Create A temp pointer P1 to move with
    if(Position < Pll->SIZE && Position > 0)        //If Condition to check that the position entered is valid
    {
        for(int i= Pll->SIZE - Position ; i>0; i--) //for loop to shift P1 to the right position
        {
            P1 = P1->Next;
        }
        Pn->Next = P1->Next;
        Pn->Previous = P1;
        P1->Next = Pn;
        if(Pn->Next)    //If there is Next
            Pn->Next->Previous = Pn;
        Pn->data = data;
        Pll->SIZE++;
    }
    else if(Position == Pll->SIZE+1)    //If condition for the special case which is the position is the top Node
    {
        Position = Pll->SIZE+1;
        Pll->top = Pn;
        Pn->Next = P1;
        Pn->Previous = NULL;
        if(Pn->Next)    //if there is only the top node in the list and there is no next node
            P1->Previous = Pn;
        Pn->data = data;
        Pll->SIZE++;
    }
    else    //if the position not valid
    {
        printf("this element is not in the List");
    }
}

void DublyAddToTheLastLLNode(LLEntry data,LinkedList *Pll)
{   //Add node to the first node
    DublyAddLLNode(data,Pll,Pll->SIZE+1);       //For Customer Satisfaction : if Add to the last node then send the size +1 As a position
}

void DublyRemoveLLNode(LLEntry *data,LinkedList *Pll, int Position)
{   //removing node with position
    LLNode *P1 = Pll->top;      //Create P1 pointer to move with
    if(Pll->SIZE >0)
    {   //there is nodes in the list
        if(Position <=Pll->SIZE && Position > 0)
        {   //If Condition to check if the position either valid or not
            for(int i= Pll->SIZE - Position ; i>0; i--)
            {   //Shift P1 to the right position
                P1 = P1->Next;
            }
            if(P1->Previous)    //if it is the First node
                P1->Previous->Next = P1->Next;
            else        //if it is not the First node
                Pll->top = P1->Next;
            if(P1->Next)    //if it is the last node
                P1->Next->Previous = P1->Previous;
            *data = P1->data;   //Copy data to send it out
            Pll->SIZE--;    //decrement the size by 1 as there is element in the list removed
            free(P1);       //Then free the P1 : the node that needs to be deleted
        }
        else
        {   //if the position is not in the list
            printf("Invalid Position");
        }
    }
    else
    {   //if there is no elements in the list
        printf("The List is empty\n");
    }
}

void DublyReplaceData(LLEntry data,LinkedList *Pll, int Position)
{   //replacing node's data
    LLNode *P1 = Pll->top;      //create P1 pointer to move with
    if(Pll->SIZE >0)
    {   //if the list is not empty
        if(Position <=Pll->SIZE && Position > 0)
        {   //check if the position is valid or not
            for(int i= Pll->SIZE - Position ; i>0; i--)
            {   //shift P1 to the right position
                P1 = P1->Next;
            }
            P1->data = data;    //Update the data in this node by the data entered
        }
        else
        {   //if the position is not valid
            printf("Invalid Position");
        }
    }
    else
    {   //if the list is empty
        printf("The List is empty\n");
    }
}

void DublyCopyData(LLEntry *data,LinkedList *Pll,int Position)
{   //copying node's data
    LLNode *P1 = Pll->top;  //Create P1 Pointer to move with
    if(Pll->SIZE >0)
    {   //if the list is empty
        if(Position <=Pll->SIZE && Position > 0)
        {   //if the position is valid
            for(int i= Pll->SIZE - Position ; i>0; i--)
            {   //shift P1 to the right position
                P1 = P1->Next;
            }
            *data = P1->data;   //Copy data in this node to the address of the entered data
        }
        else
        {   //if the position is not valid
            printf("Invalid Position");
        }
    }
    else
    {   //if the list is empty
        printf("The List is empty\n");
    }
}

void DublyRemoveLastNode(LLEntry *data,LinkedList *Pll)
{   //Customer satisfaction : if needed to delete the first node without giving position
    DublyRemoveLLNode(data, Pll, Pll->SIZE);
}

char LinkedListEmpty(LinkedList *Pll) //to check if the LinkedList is empty or not
{   //if the list is empty return 1 if it is not return 0
    return !Pll->SIZE;  //return the size of list
}

char LinkedListFull(LinkedList *Pll)
{   //return 1 if the list is full or return 0 if the list is not full
    return 0;       //return 0 as the heap is always big enough
}

int LinkedListSize(LinkedList *Pll)
{   //return the size of the list
    return Pll->SIZE;
}

void ClearLinkedList(LinkedList *Pll)
{   //function to clear the whole list at once
    LLNode *Pn = NULL;  //create a pointer to save the node in before swapping to free it, Initialize it with NULL to prevent wild pointer
    while(Pll->top)
    {   //while Pll->Top point to a node keep freeing
        Pn = Pll->top;
        Pll->top = Pn->Next;
        free(Pn);
    }
}

void MoveUpSwapLL(LinkedList *Pll,int Position)
{   //Swapping the node(position) with the above node
    LLNode *P1=Pll->top;        //create pointer P1 to move with
    if(Position < Pll->SIZE && Position >0)
    {   //if the position is valid
        for(int i=Pll->SIZE - Position ; i>0 ; i--)
        {   //shift P1 to the right position
            P1 = P1->Next;
        }
        P1->Previous->Next = P1->Next;
        if(P1->Next)    /* Check for first element */
            P1->Next->Previous = P1->Previous;
        P1->Previous = P1->Previous->Previous;
        if(P1->Previous)    /* Check for last element */
        { /* If it is not the last element */
            P1->Previous->Next->Previous=P1;
            P1->Next = P1->Previous->Next;
            P1->Previous->Next = P1;
        }
        else
        { /* if it is the last element */
            P1->Next = Pll->top;
            Pll->top->Previous = P1;
            Pll->top = P1;
        }
    }
    else
    {   //if it is either first node or wrong position
        printf("You can't swap this element, either not in the list or the last element, Try again :) \n");
    }
}

void MoveDownSwapLL(LinkedList *Pll, int Position)
{   //For Customer satisfaction : if the user want to swap down just swap up the previous position
    MoveUpSwapLL(Pll,Position-1);
}

LLNode* GetStudentNode(LinkedList *Pll)
{   //function to search for student using his ID then return the Address of the Node if available and NULL if not available
    if(Pll->SIZE)
    {
        int FoundFlag = 0;
        LLNode *P1=Pll->top;
        int ID;

        printf("Enter the ID : ");
        scanf("%d",&ID);
        while(P1)
        {
            if(ID == P1->data.ID)
            {
                FoundFlag=1;
                break;
            }
            P1=P1->Next;
        }
        if(FoundFlag == 1)
        {
            return P1;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}
