#include "Queue.h"

Queue::Queue()
{
    _head = new Node();
    _head->next = nullptr;
    _head->prev = nullptr;
    _tail = _head;
    _size = 0;
}

Queue::~Queue()
{
    while(!Empty())
    {
        Dequeue();
    }
}

void Queue::Enqueue(int data)
{
    if (_size == 0)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        _head->next = newNode;
        _tail->prev = newNode;
        _size++;
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;

    // Connect prev for _tail Trace
    _head->next->prev = newNode;

    // Connect next for _head Trace
    newNode->next = _head->next;

    // Set _head
    _head->next = newNode;
    _size++;
}

void Queue::Dequeue()
{
    if (_tail->prev == nullptr)
    {
        return;
    }

    Node* delNode = _tail->prev;
    _tail->prev = delNode->prev;
    delete delNode;
    _size--;
}

int Queue::Front() const
{
    return _tail->prev->data;
}

int Queue::Size() const
{
    return _size;
}

bool Queue::Empty() const
{
    return _size == 0;
}

void Queue::Print()
{
    if(_size == 0)
    {
        return;
    }

    Node* curNode = _tail->prev;
    while(true)
    {
        std::cout << curNode->data << " ";
        if(curNode->prev == nullptr)
        {
            break;
        }

        curNode = curNode->prev;
    }

    std::cout << "\n";
}