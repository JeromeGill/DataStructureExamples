//
//  ExtendedLinkedList.h
//  DataStructures
//
//  Created by Jerome on 27/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#ifndef __DataStructures__ExtendedLinkedList__
#define __DataStructures__ExtendedLinkedList__

#include <iostream>

typedef struct Node{
    
    Node(int data)
    {
        this->data = data;
        previous = NULL;
        next = NULL;
    }
    
    int data;
    struct Node* previous;
    struct Node* next;
} NODE;

class LinkedList
{
protected:
    NODE* front;
    NODE* back;
    int size;
    void removeNode(NODE* node);
public:
    LinkedList();
    virtual ~LinkedList();
    void appendNode(int);
    void displayNodes();
    void displayNodesReverse();
    void destroyList();
    void removeNodeAt(int);
    int findNode(int);
    void deleteNode(int);
    void insertNodeAt(int,int);
    int peek(int);
    int getSize();
};
#endif /* defined(__DataStructures__ExtendedLinkedList__) */
