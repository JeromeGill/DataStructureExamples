//
//  BinaryTree.h
//  DataStructures
//
//  Created by Jerome on 27/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#ifndef __DataStructures__BinaryTree__
#define __DataStructures__BinaryTree__

#include <iostream>

#include <string.h>
#define SIZE_KEY 32
#define SIZE_VALUE     256
typedef struct Metadata
{
    Metadata(char* key, char* value)
    {
        strcpy(this->key, key);
        strcpy(this->value, value);
        left = NULL;
        right = NULL;
    }
    char key[SIZE_KEY];
    char value[SIZE_VALUE];
    struct Metadata* left;
    struct Metadata* right;
} METADATA;
class BinarySearchTree
{
private:
    int size;
    METADATA* root;
    bool addNode(METADATA** current_node, METADATA* new_node);
    bool getNode(METADATA* current_node, char* key, char* value);
    void removeAllNodes(METADATA* node);
    void processNodesInOrder(METADATA* node);
    int getTreeDepth(METADATA* node);
    bool containsNode(METADATA* node, char* key);
    bool removeNode(METADATA** node, char* key);
    void removeRootNode(METADATA** node);
    void moveLeftMostNode(METADATA** node, METADATA* root);
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    bool add(char* key, char* value);
    bool remove(char* key);
    void removeAll();
    bool get(char* key, char* value);
    bool contains(char* key);
    void displayInOrder();
    int getSize();
    int getDepth();
};

#endif /* defined(__DataStructures__BinaryTree__) */
