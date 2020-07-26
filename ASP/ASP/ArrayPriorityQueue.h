#pragma once
#include "Queue.h"
template<class T>
class ArrayPriorityQueue : public Queue<T>
{
    int size;
    int maxSize;
    T* array;

    void ExpandQueue();
    int GetFirstElementPosition() const;
public:
    ArrayPriorityQueue(int maxSize);

    void Add(const T& item);

    T Remove();

    T Peek() const;

    bool IsEmpty() const;

    bool IsFull() const;

    ~ArrayPriorityQueue();
};

