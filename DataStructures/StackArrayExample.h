//
//  StackArrayExample.h
//  DataStructures
//
//  Created by Jerome on 15/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#ifndef __DataStructures__StackArrayExample__
#define __DataStructures__StackArrayExample__

#include <iostream>

class Stack
{
private:
    int size;
    int top;
    int* values;
    
public:
    
    Stack(int size);
    ~Stack();
    
    bool isFull();
    bool isEmpty();
    
    void push(int x);
    int pop();
   
};



#endif /* defined(__DataStructures__StackArrayExample__) */
