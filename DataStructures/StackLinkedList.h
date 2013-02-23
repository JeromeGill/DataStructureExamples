//
//  StackLinkedList.h
//  DataStructures
//
//  Created by Jerome on 23/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#ifndef __DataStructures__StackLinkedList__
#define __DataStructures__StackLinkedList__

#include <iostream>
#include "LinkedListExample.h"


class StackLinkedList : public LinkedList
{
public:
    StackLinkedList();
    virtual ~StackLinkedList();
    void push(int);
    int pop();
    bool isEmpty();
};


#endif /* defined(__DataStructures__StackLinkedList__) */
