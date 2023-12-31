#ifndef HEADER_DICTIONARY
#define HEADER_DICTIONARY

#include "List.h"

#define EXP_SIZ 5

template<class T1, class T2>
class Dictionary
{
public:
    Dictionary();

    ~Dictionary();

    void Add(T1 key, T2 value);

    T2 Find(T1 key);

    void Print();

private:
    List<T1> _keys;
    T2* _values;

    int _size;
    int _memSize;
};


template<class T1, class T2>
Dictionary<T1, T2>::Dictionary()
{
    _values = new T2[EXP_SIZ];
    _memSize = EXP_SIZ;
    _size = 0;

    if(typeid(T2).name() == typeid(int).name())
    {
        memset(_values, 0, EXP_SIZ);
        return;
    }

    memset(_values, NULL, EXP_SIZ);
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
    if (_size >= _memSize)
    {
        int prevSize = _memSize;
        _memSize += EXP_SIZ;

        T2* newMemory = new T2[_memSize];
        memset(newMemory, NULL, _memSize);

        for (int i = 0; i < prevSize; i++)
        {
            newMemory[i] = _values[i];
        }

        delete _values;
        _values = newMemory;
    }

    _keys.Add(key);
    _values[_keys.IndexOf(key)] = value;
}

template<class T1, class T2>
T2 Dictionary<T1, T2>::Find(T1 key)
{
    if (_keys.IndexOf(key) == -1)
    {
        std::cout << "Not Exist\n";
        return NULL;
    }

    return _values[_keys.IndexOf(key)];
}

template<class T1, class T2>
void Dictionary<T1, T2>::Print()
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << _keys.At(i) << " : " << _values[i] << "\n";
    }

    std::cout << "Current Memory Size : " << _memSize << "\n";
    std::cout << "Current Data Size : " << _size << "\n";
}


#endif
