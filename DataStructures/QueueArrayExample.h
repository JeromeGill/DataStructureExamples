//
//  QueueArrayExample.h
//  DataStructures
//
//  Created by Jerome on 15/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#ifndef __DataStructures__QueueArrayExample__
#define __DataStructures__QueueArrayExample__

#include <iostream>
//queue.h
#define DEFAULT_SIZE 8
class Queue{
private:
    
    int size;
    int front;
    int back;
    int* values;
    
public:
    Queue(int size = DEFAULT_SIZE);
    virtual ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int);
    int dequeue();
};

#endif /* defined(__DataStructures__QueueArrayExample__) */
