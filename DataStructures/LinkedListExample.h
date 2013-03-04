//
//  LinkedListExample.h
//  DataStructures
//
//  Created by Jerome on 23/02/2013.
////  Copyright (c) 2013 Jerome. All rights reserved.
////
//
//#ifndef __DataStructures__LinkedListExample__
//#define __DataStructures__LinkedListExample__
//
//#include <iostream>
//
//typedef struct DoublyLinkedNode
//{
//    DoublyLinkedNode(int data)
//    {
//        this->data = data;
//        previous = NULL;
//        next = NULL;
//    };
//    int data;
//    struct DoublyLinkedNode* previous;
//    struct DoublyLinkedNode* next;
//} NODE_D;
//
//
//typedef struct SinglyLinkedNode
//{
//    SinglyLinkedNode(int data)
//    {
//        this->data = data;
//        next = NULL;
//    }
//    int data;
//    struct SinglyLinkedNode* next;
//} NODE_S;
//
//
//class LinkedList
//{
//protected:
//    NODE_D* front;
//    NODE_D* back;
//public:
//    LinkedList();
//    ~LinkedList();
//    void appendNode(int);
//    void displayNodes();
//    void displayNodesReverse();
//    void destroyList();
//};
//
//#endif /* defined(__DataStructures__LinkedListExample__) */
