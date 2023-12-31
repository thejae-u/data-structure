#ifndef HEADER_STACK
#define HEADER_STACK
#include "Node.h"

class Stack
{
public:
    Stack();
    ~Stack();
    void Push(int data);
    void Pop();
    int Top() const;
    bool Empty() const;
    int Size() const;
    void Print();

private:
    Node* _top;
    int _size;
};

#endif
