//
//  main.cpp
//  DataStructures
//
//  Created by Jerome on 15/02/2013.
//  Copyright (c) 2013 Jerome. All rights reserved.
//

#include <iostream>
#include "StackArrayExample.h"
#include "QueueArrayExample.h"
#include "TemplateLinkedList.h"

int main()
{

    TemplateLinkedList<float> list;
    list.appendNode(10.5);
    list.appendNode(14.2);
    
    list.displayNodes();
    //std::cout<<<<"\n";

    return 0;
}

