#pragma once

#include <stdexcept>

#include "HashTable.h"
#include "HashNode.h"

template<typename TKey, typename TValue>
class OpenAddressHashTable : public HashTable<TKey, TValue>
{
    int elementsCount;
    HashNode<TKey, TValue>** array;
public:
    OpenAddressHashTable(int max = 10);
    void Add(const TKey& key, const TValue& value);
    bool Remove(const TKey& key);
    bool IsEmpty() const;
    bool IsFull() const;
    HashNode<TKey, TValue>* Get(const TKey& key) const;
    ~OpenAddressHashTable();
};

template<typename TKey, typename TValue>
OpenAddressHashTable<TKey, TValue>::OpenAddressHashTable(int max) : HashTable<TKey, TValue>::maxSize(max)
{
    array = new HashNode<TKey, TValue> *[max];
    for (int i = 0; i < max; i++)
        array[i] = nullptr;
}

template<typename TKey, typename TValue>
void OpenAddressHashTable<TKey, TValue>::Add(const TKey& key, const TValue& value)
{
    if (IsFull()) throw std::exception("Greska, the hash table is full!");

    int i = HashTable<TKey, TValue>::GetHash(key);
    int start = i;
    while (array[i])
    {
        i++;
        if (i == HashTable<TKey, TValue>::maxSize) i = 0;

        if (i == start) return;
    }

    array[i] = new HashNode<TKey, TValue>(key, value);
    elementsCount++;
}

template<typename TKey, typename TValue>
bool OpenAddressHashTable<TKey, TValue>::Remove(const TKey& key)
{
    if (!IsEmpty())
    {
        int i = HashTable<TKey, TValue>::GetHash(key);
        int start = 0;
        while (1)
        {
            if (array[i] && array[i]->GetKey() == key)
            {
                elementsCount--;
                delete array[i];
                array[i] = nullptr;
                return true;
            }

            i++;
            if (i == HashTable<TKey, TValue>::maxSize) i = 0;
            if (i == start) break;
        }
    }
    
    return false;
}

template<typename TKey, typename TValue>
bool OpenAddressHashTable<TKey, TValue>::IsEmpty() const
{
    return elementsCount == 0;
}

template<typename TKey, typename TValue>
bool OpenAddressHashTable<TKey, TValue>::IsFull() const
{
    return elementsCount == HashTable<TKey, TValue>::maxSize;
}

template<typename TKey, typename TValue>
HashNode<TKey, TValue>* OpenAddressHashTable<TKey, TValue>::Get(const TKey& key) const
{
    if (!IsEmpty())
    {
        int i = HashTable<TKey, TValue>::GetHash(key);
        int start = i;
        while (1)
        {
            if (array[i] && array[i]->GetKey() == key)
                return array[i];


            i++;
            if (i == HashTable<TKey, TValue>::maxSize) i = 0;

            if (i == start) return nullptr;
        }
    }

    return nullptr;
}

template<typename TKey, typename TValue>
OpenAddressHashTable<TKey, TValue>::~OpenAddressHashTable()
{
    for (int i = 0; i < HashTable<TKey, TValue>::maxSize; i++)
        delete array[i];
    delete[] array;
}
