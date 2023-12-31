#include "List.h"

List::List()
{
    _size = 0;
    _head = new Node();
    _head->next = nullptr;
}

List::~List()
{
    while (!Empty())
    {
        Remove();
    }

    delete _head;
}

void List::Add(int data)
{
    Node* newNode = new Node();
    newNode->data = data;

    if (_size == 0)
    {
        newNode->next = nullptr;
        _head->next = newNode;
        _size++;
        return;
    }

    Node* curNode = _head->next;
    while (curNode->next != nullptr)
    {
        curNode = curNode->next;
    }

    curNode->next = newNode;
    _size++;
}

void List::AddAt(int idx, int data)
{
    if (idx <= 0 && idx > _size)
    {
        return;
    }

    if (_size == 0)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        _head = newNode;
        _size++;
        return;
    }

    Node* curNode = _head;

    for (int i = 0; i < idx - 1; i++)
    {
        curNode = curNode->next;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = curNode->next;
    curNode->next = newNode;
    _size++;
}

void List::Remove()
{
    if (_size == 0)
    {
        return;
    }


    if(_size == 1)
    {
        delete _head->next;
        _size--;
        return;
    }

    Node* curNode = _head->next;
    while(curNode->next->next != nullptr)
    {
        curNode = curNode->next;
    }

    Node* delNode = curNode->next;
    curNode->next = nullptr;
    delete delNode;
    _size--;
}

void List::RemoveAt(int idx)
{
    if (idx > _size || idx <= 0)
    {
        return;
    }

    Node* curNode = _head;
    for (int i = 0; i < idx - 1; i++)
    {
        curNode = curNode->next;
    }

    Node* delNode = curNode->next;
    curNode->next = delNode->next;
    delete delNode;
    _size--;
}

bool List::Empty() const
{
    return _size == 0;
}

int List::Size() const
{
    return _size;
}

void List::Print()
{
    if (_size == 0)
    {
        return;
    }

    Node* curNode = _head->next;
    while (true)
    {
        std::cout << curNode->data << " ";
        if (curNode->next == nullptr)
        {
            break;
        }

        curNode = curNode->next;
    }
    std::cout << "\n";
}