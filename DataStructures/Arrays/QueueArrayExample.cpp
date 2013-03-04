//
//  QueueArrayExample.cpp
//  DataStructures
//
//  Created by Jerome on 15/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

//queue.cpp

#include "QueueArrayExample.h"



Queue::Queue(int size)
{
    this->size = size;
    values = new int[size];
    front = 0;
    back = 0;
}
Queue::~Queue()
{
    delete[] values;
}
bool Queue::isFull()
{
    if( (back+1) % size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue::isEmpty()
{
    if(back == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::enqueue(int x)
{
    if(!isFull())
    {
        back = (back+1) % size;
        values[back] = x; //Queue[back] in the book but the array is declared as values* in the header
    }
}
int Queue::dequeue()
{
    if(!isEmpty())
    {
        front = (front+1) % size;
        return values[front];
    }
    return 0;
}