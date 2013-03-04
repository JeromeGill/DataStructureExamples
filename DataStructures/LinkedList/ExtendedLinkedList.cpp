//
//  ExtendedLinkedList.cpp
//  DataStructures
//
//  Created by Jerome on 27/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#include "ExtendedLinkedList.h"

LinkedList::LinkedList()
{
    front = NULL;
    back = NULL;
    size = 0;
}

LinkedList::~LinkedList()
{
    destroyList();
}

void LinkedList::appendNode(int data)
{
    NODE* n = new NODE(data);
    
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
    
    size++;
}

void LinkedList::displayNodes()
{
    std::cout << "Elements: ";
    NODE* temp = front;
    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    
    std::cout << std::endl;
    
}

void LinkedList::displayNodesReverse()
{
    std::cout << "Elements: ";
    NODE* temp = back;
    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->previous;
    }
    
    std::cout << std::endl;
}

void LinkedList::destroyList()
{
    NODE* temp = back;
    while(temp != NULL)
    {
        NODE* temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
    
    back = NULL;
    front = NULL;
}

void LinkedList::removeNode(NODE* node)
{
    if(node->previous == NULL && node->next == NULL)
    {
        back = NULL;
        front = NULL;
    }
    else if(node->previous == NULL)
    {
        front = node->next;
        node->next->previous = NULL;
    }
    else if(node->next == NULL)
    {
        back = node->previous;
        node->previous->next = NULL;
    }
    else
    {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
    
    delete node;
    size--;
}

void LinkedList::removeNodeAt(int index)
{
    if(index < 0 || index > size-1)
    {
        return;
    }
    
    NODE* temp_node = front;
    
    for(int i=0; i<index; i++)
    {
        temp_node = temp_node->next;
    }
    
    removeNode(temp_node);
}

int LinkedList::findNode(int data)
{
    int index = 0;
    NODE* temp_node = front;
    
    while(temp_node != NULL)
    {
        if(temp_node->data == data)
        {
            // return the index of the node
            return index;
        }
        else
        {
            temp_node = temp_node->next;
            index++;
        }
    }
    
    return -1;
}

void LinkedList::deleteNode(int data)
{
    NODE* temp_node = front;
    
    while(temp_node != NULL)
    {
        if(temp_node->data == data)
        {
            removeNode(temp_node);
            return;
        }
        else
        {
            temp_node = temp_node->next;
        }
    }
}

void LinkedList::insertNodeAt(int index, int data)
{
    if(index < 0 || index > size)
    {
        return;
    }
    
    NODE* new_node = new NODE(data);
    
    if(size == 0)
    {
        front = new_node;
        back = new_node;
    }
    else if(index == 0)
    {
        front->previous = new_node;
        new_node->next = front;
        front = new_node;
    }
    else if(index == size)
    {
        back->next = new_node;
        new_node->previous = back;
        back = new_node;
    }
    else
    {
        NODE* temp = front;
        
        for(int i=0; i<index; i++)
        {
            temp = temp->next;
        }
        
        new_node->next = temp;
        new_node->previous = temp->previous;
        
        temp->previous->next = new_node;
        temp->previous = new_node;
    }
    
    size++;
}

int LinkedList::peek(int index)
{
    if(index < 0 || index > size-1)
    {
        return 0;
    }
    
    NODE* temp = front;
    
    for(int i=0; i<index; i++)
    {
        temp = temp->next;
    }
    
    return temp->data;
    
}

int LinkedList::getSize()
{
    return size;
}
