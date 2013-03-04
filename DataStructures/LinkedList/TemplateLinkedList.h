//
//  LinkedListExample.h
//  DataStructures
//
//  Created by Andy on 23/02/2013.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#ifndef __DataStructures__LinkedListExample__
#define __DataStructures__LinkedListExample__

#include <iostream>


template <class T>
class TemplateNode {
public:
    TemplateNode (T data)
    {
        this->data = data;
        previous = NULL;
        next = NULL;
    }
    
    T data;
    TemplateNode* previous;
    TemplateNode* next;
};

template <typename T>
class TemplateLinkedList
{
protected:
    TemplateNode<T>* front;
    TemplateNode<T>* back;
    int size;
    void removeNode(TemplateNode<T>* node);
    
public:
    TemplateLinkedList();
    virtual ~TemplateLinkedList();
    void appendNode(T number);
    void displayNodes();
    void displayNodesReverse();
    void destroyList();

    void removeNodeAt(int index);
    int findNode(T data);
    void deleteNode(T data);
    void insertNodeAt(int index,T data);
    T peek(int index);
    int getSize();
};

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

#endif /* defined(__DataStructures__LinkedListExample__) */
