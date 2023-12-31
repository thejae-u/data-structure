#ifndef HEADER_STACK
#define HEADER_STACK

#include "Node.h"

template<class T>
class Stack
{
public:
    Stack();

    ~Stack();

    void Push(T data);

    void Pop();

    T Top() const;

    bool Empty() const;

    int Size() const;

    void Print() const;

private:
    Node<T>* _top;
    int _size;
};

template<class T>
Stack<T>::Stack()
{
    _size = 0;
    _top = new Node<T>();
    _top->next = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
    while (!Empty())
    {
        Pop();
    }

    delete _top;
}

template<class T>
void Stack<T>::Push(T data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;

    if (_size == 0)
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

template<class T>
void Stack<T>::Pop()
{
    if (_size == 0)
    {
        return;
    }

    Node<T>* delNode = _top->next;
    _top->next = delNode->next;
    delete delNode;
    _size--;
}

template<class T>
T Stack<T>::Top() const
{
    if (_size == 0)
    {
        return NULL;
    }

    return _top->data;
}

template<class T>
bool Stack<T>::Empty() const
{
    return _size == 0;
}

template<class T>
int Stack<T>::Size() const
{
    return _size;
}

template<class T>
void Stack<T>::Print() const
{
    if (_size == 0)
    {
        return;
    }

    std::cout << "-----------\n";
    Node<T>* curNode = _top->next;
    do
    {
        std::cout << curNode->data << "\n";
        curNode = curNode->next;
    } while (curNode);

    std::cout << "-----------\n";
}

#endif
