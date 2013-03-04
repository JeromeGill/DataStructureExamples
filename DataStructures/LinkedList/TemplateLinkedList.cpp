//
//  TemplateLinkedList.cpp
//  DataStructures
//
//  Created by Andy on 04/03/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#include <iostream>
#include "TemplateLinkedList.h"

template <typename T>
TemplateLinkedList<T>::TemplateLinkedList()
{
    front = NULL;
    back = NULL;
}

template <typename T>
TemplateLinkedList<T>::~TemplateLinkedList()
{
    destroyList();
}

template <typename T>
void TemplateLinkedList<T>::appendNode(T number)
{
    TemplateNode<T>* n = new TemplateNode<T>(number);
    
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

template <typename T>
void TemplateLinkedList<T>::displayNodes()
{
    std::cout << "Nodes:";
    TemplateNode<T>* temp = front;
    while(temp != NULL)
    {
        std::cout << " " << temp->data;
        temp = temp->next;
    }
}

template <typename T>
void TemplateLinkedList<T>::displayNodesReverse()
{
    std::cout << "Nodes in reverse order:";
    TemplateNode<T>* temp = back;
    while(temp != NULL)
    {
        std::cout << " " <<  temp->data;
        temp = temp->previous;
    }
}

template <typename T>
void TemplateLinkedList<T>::destroyList()
{
    TemplateNode<T>* temp = back;
    while(temp != NULL)
    {
        TemplateNode<T>* temp2 = temp;
        temp = temp->previous;
        delete temp2;
    }
    back = NULL;
    front = NULL;
}

template <typename T>
void TemplateLinkedList<T>::removeNodeAt(int index)
{
    if(index < 0 || index > size-1)
    {
        return;
    }
    
    TemplateNode<T>* temp_node = front;
    
    for(int i=0; i<index; i++)
    {
        temp_node = temp_node->next;
    }
    
    removeNode(temp_node);
}

template <typename T>
int TemplateLinkedList<T>::findNode(T data)
{
    int index = 0;
    TemplateNode<T>* temp_node = front;
    
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

template <typename T>
void TemplateLinkedList<T>::deleteNode(T data)
{
    TemplateNode<T>* temp_node = front;
    
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

template <typename T>
void TemplateLinkedList<T>::insertNodeAt(int index, T data)
{
    if(index < 0 || index > size)
    {
        return;
    }
    
    TemplateNode<T>* new_node = new TemplateNode<T>(data);
    
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
        TemplateNode<T>* temp = front;
        
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

template <typename T>
T TemplateLinkedList<T>::peek(int index)
{
    if(index < 0 || index > size-1)
    {
        return 0;
    }
    
    TemplateNode<T>* temp = front;
    
    for(int i=0; i<index; i++)
    {
        temp = temp->next;
    }
    
    return temp->data;
    
}

template <typename T>
int TemplateLinkedList<T>::getSize()
{
    return size;
}