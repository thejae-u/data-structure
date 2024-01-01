#ifndef HEADER_DICTIONARY
#define HEADER_DICTIONARY

#include "List.h"
#include <cassert>

#define EXP_SIZ 5

template<class T1, class T2>
class Dictionary
{
public:
    Dictionary();

    ~Dictionary();

    void Add(T1 key, T2 value);

    void Remove(T1 key);

    T2 Find(T1 key);

    int Size() const;

    bool Empty() const;

    void Print() const;

private:
    List<T1> _keys;
    T2* _values;

    int _size;
    int _memSize;

    void MemorySet(T2* mem);
};

template<class T1, class T2>
void Dictionary<T1, T2>::MemorySet(T2* mem)
{
    if (typeid(T2) == typeid(int))
    {
        for (int i = 0; i < _memSize; i++)
        {
            mem[i] = 0;
        }

        assert(mem[0] == 0);
        return;
    }

    for (int i = 0; i < _memSize; i++)
    {
        mem[i] = NULL;
        assert(mem[0] == NULL);
    }
}

template<class T1, class T2>
Dictionary<T1, T2>::Dictionary()
{
    _values = new T2[EXP_SIZ];
    _memSize = EXP_SIZ;
    _size = 0;

    MemorySet(_values);
}

template<class T1, class T2>
Dictionary<T1, T2>::~Dictionary()
{
    delete[] _values;
}

template<class T1, class T2>
void Dictionary<T1, T2>::Add(T1 key, T2 value)
{
    if (_keys.IndexOf(key) != -1)
    {
        std::cout << "Invalid Key : Already Exist\n";
        return;
    }

    _size++;

    // Memory Resize
    if (_size == _memSize)
    {
        int prevSize = _memSize;
        _memSize += EXP_SIZ;

        T2* newMemory = new T2[_memSize];

        MemorySet(newMemory);

        for (int i = 0; i < prevSize; i++)
        {
            newMemory[i] = _values[i];
        }

        delete[] _values;
        _values = newMemory;
    }

    _keys.Add(key);
    _values[_keys.IndexOf(key) - 1] = value;
}

template<class T1, class T2>
void Dictionary<T1, T2>::Remove(T1 key)
{
    if (_keys.IndexOf(key) == -1)
    {
        std::cout << "Invalid Key : Not Exist\n";
        return;
    }

    int idx = _keys.IndexOf(key);
    _keys.RemoveAt(idx);
    _size--;

    for (int i = idx - 1; i < _size; i++)
    {
        _values[i] = _values[i + 1];
    }

    // Memory Size Check
    if ((_memSize - _size) > EXP_SIZ)
    {
        // Resize Memory
        _memSize -= EXP_SIZ;

        T2* newMemory = new T2[_memSize];

        MemorySet(newMemory);

        for (int i = 0; i < _size; i++)
        {
            newMemory[i] = _values[i];
        }

        delete[] _values;
        _values = newMemory;
    }
}

template<class T1, class T2>
T2 Dictionary<T1, T2>::Find(T1 key)
{
    if (_keys.IndexOf(key) == -1)
    {
        std::cout << "Invalid Key : Not Exist\n";
        return NULL;
    }

    return _values[_keys.IndexOf(key) - 1];
}

template<class T1, class T2>
int Dictionary<T1, T2>::Size() const
{
    return _size;
}

template<class T1, class T2>
bool Dictionary<T1, T2>::Empty() const
{
    return _size == 0;
}

template<class T1, class T2>
void Dictionary<T1, T2>::Print() const
{
    if (_size == 0)
    {
        return;
    }

    std::cout << "---------------\n";
    for (int i = 0; i < _size; i++)
    {
        std::cout << _keys.At(i + 1) << " : " << _values[i] << "\n";
    }

    std::cout << "Current Memory Size : " << _memSize << "\n";
    std::cout << "Current Data Size : " << _size << "\n";
}


#endif
