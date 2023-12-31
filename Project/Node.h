#ifndef HEADER_NODE
#define HEADER_NODE
#include <iostream>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

#endif