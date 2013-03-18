//
//  QueueLinkedList.h
//  DataStructures
//
//  Created by Jerome on 23/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#ifndef __DataStructures__QueueLinkedList__
#define __DataStructures__QueueLinkedList__

#include <iostream>
#include "ExtendedLinkedList.h"
class QueueLinkedList : public LinkedList
{
public:
    QueueLinkedList();
    virtual ~QueueLinkedList();
    void enqueue(int);
    int dequeue();
    bool isEmpty();
};

#endif /* defined(__DataStructures__QueueLinkedList__) */
