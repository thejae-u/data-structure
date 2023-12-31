#ifndef HEADER_List
#define HEADER_List
#include "Node.h"

class List
{
public:
    List();
    ~List();
    void Add(int data);
    void AddAt(int idx, int data);
    void Remove();
    void RemoveAt(int idx);
    bool Empty() const;
    int Size() const;
    void Print();

private:
    Node* _head;
    int _size;
};
#endif
