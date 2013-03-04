//
//  LinkedListExample.cpp
//  DataStructures
//
//  Created by Jerome on 23/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#include "LinkedListExample.h"

BasicLinkedList::BasicLinkedList()
{
    front = NULL;
    back = NULL;
}

BasicLinkedList::~BasicLinkedList()
{
    destroyList();
}

void BasicLinkedList::appendNode(int data)
{
    NODE_D* n = new NODE_D(data);
    
    if(back == NULL)
    {
        back = n;
        front = n;
    }
    else
    {
        back->next = n;
        n->previous = back;
        back = n;
    }
}

void BasicLinkedList::displayNodes()
{
    std::cout << "Nodes:";
    NODE_D* temp = front;
    while(temp != NULL)
    {
        std::cout << " " << temp->data;
        temp = temp->next;
    }
}

void BasicLinkedList::displayNodesReverse()
{
    std::cout << "Nodes in reverse order:";
    NODE_D* temp = back;
    while(temp != NULL)
    {
        std::cout << " " <<  temp->data;
        temp = temp->previous;
    }
}

void BasicLinkedList::destroyList()
{
    NODE_D* temp = back;
    while(temp != NULL)
    {
        NODE_D* temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
    back = NULL;
    front = NULL;
}