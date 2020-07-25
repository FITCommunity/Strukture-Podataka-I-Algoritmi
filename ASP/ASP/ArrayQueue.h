#pragma once
#include "Queue.h"
template<class T>
class ArrayQueue : public Queue<T>
{
    int size;
    int maxSize;
    int first;
    int last;
    T* array;

    void ExpandQueue();
public:
    ArrayQueue(int maxSize);

    void Add(const T& item);
    
    T Remove();
    
    T Peek() const;
    
    bool IsEmpty() const;
    
    bool IsFull() const;

    ~ArrayQueue();
};

