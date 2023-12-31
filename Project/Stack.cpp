#include "Stack.h"

Stack::Stack()
{
    _size = 0;
    _top = new Node();
    _top->next = nullptr;
}

Stack::~Stack()
{
    while (!Empty())
    {
        Pop();
    }

    delete _top;
}

void Stack::Push(int data)
{
    Node* newNode = new Node();
    newNode->data = data;

    if(_size == 0)
    {
        newNode->next = nullptr;
        _top->next = newNode;
        _size++;
        return;
    }

    newNode->next = _top->next;
    _top->next = newNode;
    _size++;
}

void Stack::Pop()
{
    if(Empty())
    {
        return;
    }

    Node* delNode = _top->next;
    _top->next = delNode->next;
    delete delNode;
    _size--;
}

int Stack::Top() const
{
    if(_size == 0)
    {
        return 0;
    }

    return _top->data;
}

bool Stack::Empty() const
{
    return _size == 0;
}

int Stack::Size() const
{
    return _size;
}

void Stack::Print()
{
    if(_size == 0)
    {
        return;
    }

    std::cout << "-----------\n";
    Node* curNode = _top;
    while(true)
    {
        std::cout << curNode->data << "\n";
        if(curNode->next == nullptr)
            break;
        curNode = curNode->next;
    }

    std::cout << "-----------\n";
}

