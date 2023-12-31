#ifndef HEADER_QUEUE
#define HEADER_QUEUE
#include "Node.h"

class Queue
{
public:
    Queue();
    ~Queue();
    void Enqueue(int data);
    void Dequeue();
    int Size() const;
    int Front() const;
    bool Empty() const;
    void Print();

private:
    Node* _head;
    Node* _tail;
    int _size;
};

#endif
