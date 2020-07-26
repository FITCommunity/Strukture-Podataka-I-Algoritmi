#pragma once
#include "Queue.h"
template<class T>
class HeapPriorityQueue : public Queue<T>
{
    int size;
    int maxSize;
    T* array;

    int GetRightChildPosition(int i) const;
    int GetLeftChildPosition(int i) const;
    int GetParentPosition(int i) const;

    bool HasRightChild(int i) const;
    bool HasLeftChild(int i) const;

    bool IsRoot(int i) const;
    bool IsLeaf(int i) const;

    void BubbleUp(int i);
    void BubbleDown(int i = 0);

    void ExpandQueue();
public:
    HeapPriorityQueue(int maxSize);

    void Add(const T& item);

    T Remove();

    T Peek() const;

    bool IsEmpty() const;

    bool IsFull() const;

    ~HeapPriorityQueue();
};

