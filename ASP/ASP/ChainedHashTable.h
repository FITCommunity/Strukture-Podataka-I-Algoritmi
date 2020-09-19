#pragma once

#include "HashTable.h"
#include "LinkedList.h"

template<typename T>
class ChainedHashTable : public HashTable<T>
{
    LinkedList<T>* list;
public:
    ChainedHashTable(int max = 10);
    void Add(const T& item);
    bool Remove(const T& item);
    ~ChainedHashTable();
};

template<typename T>
ChainedHashTable<T>::ChainedHashTable(int max) : 
    HashTable<T>(max),
    list(new LinkedList<T>[max])
{}

template<typename T>
void ChainedHashTable<T>::Add(const T& item)
{
    list[HashTable<T>::GetHash(item)].Add(item);
}

template<typename T>
bool ChainedHashTable<T>::Remove(const T& item)
{
    return list[HashTable<T>::GetHash(item)].Remove(item);
}

template<typename T>
ChainedHashTable<T>::~ChainedHashTable()
{
    delete[] list;
}
