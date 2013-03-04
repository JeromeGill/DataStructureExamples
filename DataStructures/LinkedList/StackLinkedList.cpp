//
//  StackLinkedList.cpp
//  DataStructures
//
//  Created by Jerome on 23/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#include "StackLinkedList.h"

StackLinkedList::StackLinkedList()
{
}
StackLinkedList::~StackLinkedList()
{
}
void StackLinkedList::push(int x)
{
    appendNode(x);
}
int StackLinkedList::pop()
{
    if(isEmpty())
    {
        return -1;
    }
    
    int retVal = back->data;
    NODE* temp = back;
    
    if(back->previous == NULL)
    {
        back = NULL;
        front = NULL;
    }
    
    else
    {
        back = back->previous;
        back->next = NULL;
    }
    delete temp;
    return retVal;
}
bool StackLinkedList::isEmpty()
{
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}