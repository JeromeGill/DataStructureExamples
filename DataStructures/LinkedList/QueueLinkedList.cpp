//
//  QueueLinkedList.cpp
//  DataStructures
//
//  Created by Jerome on 23/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#include "QueueLinkedList.h"

QueueLinkedList::QueueLinkedList()
{
}
QueueLinkedList::~QueueLinkedList()
{
}
void QueueLinkedList::enqueue(int x)
{
    appendNode(x);
}

int QueueLinkedList::dequeue()
{
    if(isEmpty())
    {
        return -1;
    }
    
    int retVal = front->data;
    NODE* temp = front;
    
    if(front->next == NULL)
    {
        back = NULL;
        front = NULL;
    }
    else
    {
        front = front->next;
        front->previous = NULL;
    }
    delete temp;
    return retVal;
}

bool QueueLinkedList::isEmpty()
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