#ifndef HEADER_NODE
#define HEADER_NODE
#include <iostream>

template <class T>
struct Node
{
    T data;
    struct Node* next;
    struct Node* prev;
};

#endif