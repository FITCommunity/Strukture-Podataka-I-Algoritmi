#pragma once

template<typename T>
class HashTable
{
    int maxSize;
protected:
    int GetHash(const T& item) const
    {
        return item % maxSize;
    }

    int GetMaxSize() const { return maxSize; }
public:
    HashTable(int maxSize = 20) : maxSize(maxSize) {}
    virtual void Add(const T&) = 0;
    virtual bool Remove(const T&) = 0;
};

