#pragma once

#include "HashTable.h"
#include "ArrayList.h"
#include "HashNode.h"

template<typename TKey, typename TValue>
class ChainedHashTable : public HashTable<TKey, TValue>
{
    ArrayList<HashNode<TKey, TValue>>* list;
public:
    ChainedHashTable(int max = 10);
    void Add(const TKey& key, const TValue& value);
    bool Remove(const TKey& key);
    HashNode<TKey, TValue>* Get(const TKey& key, const TValue &value) const;
    ~ChainedHashTable();
};

template<typename TKey, typename TValue>
ChainedHashTable<TKey, TValue>::ChainedHashTable(int max) : 
    HashTable<TKey, TValue>::maxSize(max),
    list(new ArrayList<HashNode<TKey, TValue>>[max])
{}

template<typename TKey, typename TValue>
void ChainedHashTable<TKey, TValue>::Add(const TKey& key, const TValue& value)
{
    list[HashTable<TKey, TValue>::GetHash(key)].Add({ key, value });
}

template<typename TKey, typename TValue>
bool ChainedHashTable<TKey, TValue>::Remove(const TKey& key)
{
    return list[HashTable<TKey, TValue>::GetHash(key)].Remove();
}

template<typename TKey, typename TValue>
HashNode<TKey, TValue>* ChainedHashTable<TKey, TValue>::Get(const TKey& key, const TValue& value) const
{
    ArrayList<HashNode<TKey, TValue>> temp = list[HashTable<TKey, TValue>::GetHash(key)];
    return temp.Get({ key, value });

}

template<typename TKey, typename TValue>
ChainedHashTable<TKey, TValue>::~ChainedHashTable()
{
    delete[] list;
}
