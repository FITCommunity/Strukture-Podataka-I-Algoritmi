#pragma once

template<typename TKey, typename TValue>
class HashTable
{
    int maxSize;
    int GetHash(const TKey& key)
    {
        return key % maxSize;
    }
public:
    virtual void Add(const TKey& key, const TValue& value) = 0;
    virtual bool Remove(const TKey& key) = 0;
};

