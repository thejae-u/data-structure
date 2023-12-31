#ifndef HEADER_QUEUE
#define HEADER_QUEUE
#include "Node.h"

template <class T>
class Queue
{
public:
    Queue();
    ~Queue();
    void Enqueue(T data);
    void Dequeue();
    int Size() const;
    T Front() const;
    bool Empty() const;
    void Print();

private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;
};

template <class T>
Queue<T>::Queue()
{
    _head = new Node<T>();
    _head->next = nullptr;
    _head->prev = nullptr;
    _tail = new Node<T>();
    _tail->next = nullptr;
    _tail->prev = nullptr;
    _size = 0;
}

template <class T>
Queue<T>::~Queue()
{
    while(!Empty())
    {
        Dequeue();
    }

    delete _head;
    delete _tail;
}

template <class T>
void Queue<T>::Enqueue(T data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;

    if (_size == 0)
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        _head->next = newNode;
        _tail->prev = newNode;
        _size++;
        return;
    }

    newNode->prev = nullptr;

    // Connect prev for _tail Trace
    _head->next->prev = newNode;

    // Connect next for _head Trace
    newNode->next = _head->next;

    // Set _head
    _head->next = newNode;
    _size++;
}

template <class T>
void Queue<T>::Dequeue()
{
    if (_tail->prev == nullptr)
    {
        return;
    }

    Node<T>* delNode = _tail->prev;
    _tail->prev = delNode->prev;
    delete delNode;
    _size--;
}

template <class T>
T Queue<T>::Front() const
{
    return _tail->prev->data;
}

template <class T>
int Queue<T>::Size() const
{
    return _size;
}

template <class T>
bool Queue<T>::Empty() const
{
    return _size == 0;
}

template <class T>
void Queue<T>::Print()
{
    if(_size == 0)
    {
        return;
    }

    if(_size == 0)
    {
        return;
    }

    Node<T>* curNode = _tail->prev;
    do
    {
        std::cout << curNode->data <<" ";
        curNode = curNode->prev;
    }while(curNode);

    std::cout << "\n";
}

#endif
