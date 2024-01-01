#ifndef HEADER_List
#define HEADER_List

#include "Node.h"

template<class T>
class List
{
public:
    List();
    ~List();
    void Add(T data);
    void AddAt(int idx, T data);
    void Remove();
    void RemoveAt(int idx);
    int IndexOf(T data) const;
    T At(int idx) const;
    bool Empty() const;
    int Size() const;
    void Print() const;

private:
    Node<T>* _head;
    int _size;
};

template<class T>
List<T>::List()
{
    _size = 0;
    _head = new Node<T>();
    _head->next = nullptr;
}

template<class T>
List<T>::~List()
{
    while (!Empty())
    {
        Remove();
    }

    delete _head;
}

template<class T>
void List<T>::Add(T data)
{
    Node<T>* newNode = new Node<T>();
    newNode->data = data;

    if (_size == 0)
    {
        newNode->next = nullptr;
        _head->next = newNode;
        _size++;
        return;
    }

    Node<T>* curNode = _head->next;
    while (curNode->next != nullptr)
    {
        curNode = curNode->next;
    }

    curNode->next = newNode;
    _size++;
}

template<class T>
void List<T>::AddAt(int idx, T data)
{
    if (idx <= 0 && idx > _size)
    {
        return;
    }

    Node<T>* newNode = new Node<T>();
    newNode->data = data;

    if (_size == 0)
    {
        newNode->next = nullptr;
        _head = newNode;
        _size++;
        return;
    }

    Node<T>* curNode = _head;

    for (int i = 0; i < idx - 1; i++)
    {
        curNode = curNode->next;
    }

    newNode->next = curNode->next;
    curNode->next = newNode;
    _size++;
}

template<class T>
void List<T>::Remove()
{
    if (_size == 0)
    {
        return;
    }


    if (_size == 1)
    {
        delete _head->next;
        _size--;
        return;
    }

    Node<T>* curNode = _head->next;
    while (curNode->next->next != nullptr)
    {
        curNode = curNode->next;
    }

    Node<T>* delNode = curNode->next;
    curNode->next = nullptr;
    delete delNode;
    _size--;
}

template<class T>
void List<T>::RemoveAt(int idx)
{
    if (idx > _size || idx <= 0)
    {
        return;
    }

    Node<T>* curNode = _head;
    for (int i = 0; i < idx - 1; i++)
    {
        curNode = curNode->next;
    }

    Node<T>* delNode = curNode->next;
    curNode->next = delNode->next;
    delete delNode;
    _size--;
}

template<class T>
int List<T>::IndexOf(T data) const
{
    if(_size == 0)
    {
        return -1;
    }

    int idx = 1;
    Node<T>* curNode = _head->next;
    while (curNode->data != data)
    {
        idx++;
        curNode = curNode->next;
        if (curNode == nullptr)
        {
            return -1;
        }
    }

    return idx;
}

template<class T>
T List<T>::At(int idx) const
{
    Node<T>* curNode = _head->next;
    for (int i = 1; i < idx; i++)
    {
        curNode = curNode->next;
    }

    return curNode->data;
}

template<class T>
bool List<T>::Empty() const
{
    return _size == 0;
}

template<class T>
int List<T>::Size() const
{
    return _size;
}

template<class T>
void List<T>::Print() const
{
    if (_size == 0)
    {
        return;
    }

    Node<T>* curNode = _head->next;
    do
    {
        std::cout << curNode->data << " ";
        curNode = curNode->next;
    } while (curNode);

    std::cout << "\n";
}

#endif
