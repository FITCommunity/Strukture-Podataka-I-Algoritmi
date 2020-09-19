#pragma once

#include <stdexcept>

#include "HashTable.h"

template<typename T>
class OpenAddressHashTable : public HashTable<T>
{
    int elementsCount;
    T* array;
    bool* isTaken;
public:
    OpenAddressHashTable(int max = 10);
    void Add(const T &item);
    bool Remove(const T& item);
    bool IsEmpty() const;
    bool IsFull() const;
    ~OpenAddressHashTable();
};

template<typename T>
OpenAddressHashTable<T>::OpenAddressHashTable(int max) : HashTable<T>(max)
{
    array = new T[max];
    isTaken = new bool[max];
    for (int i = 0; i < max; i++)
        isTaken[i] = false;
}

template<typename T>
void OpenAddressHashTable<T>::Add(const T& item)
{
    if (IsFull()) throw std::exception("Greska, the hash table is full!");

    int i = GetHash(item);
    int start = i;
    while (isTaken[i])
    {
        i++;
        if (i == GetMaxSize()) i = 0;
    }

    array[i] = item;
    isTaken[i] = true;
    elementsCount++;
}

template<typename T>
bool OpenAddressHashTable<T>::Remove(const T& item)
{
    if (!IsEmpty())
    {
        int i = GetHash(item);
        int start = 0;
        while (start != elementsCount)
        {
            if (isTaken[i] && array[i] == item)
            {
                isTaken[i] = false;
                elementsCount--;
                return true;
            }

            i++;
            start++;
            if (i == GetMaxSize()) i = 0;
        }
    }
    
    return false;
}

template<typename T>
bool OpenAddressHashTable<T>::IsEmpty() const
{
    return elementsCount == 0;
}

template<typename T>
bool OpenAddressHashTable<T>::IsFull() const
{
    return elementsCount == GetMaxSize();
}


template<typename T>
OpenAddressHashTable<T>::~OpenAddressHashTable()
{
    delete[] array;
}
