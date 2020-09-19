#pragma once

#include <utility>
#include <iostream>
#include <stdexcept>

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
    HeapPriorityQueue(int maxSize = 20);

    void Add(const T& item);

    T Remove();

    T Peek() const;

    bool IsEmpty() const;

    bool IsFull() const;

    int Size() const;

    ~HeapPriorityQueue();
};

template<class T>
HeapPriorityQueue<T>::HeapPriorityQueue(int maxSize) : size(0), maxSize(maxSize)
{
    array = new T[maxSize];
}


template<class T>
int HeapPriorityQueue<T>::GetRightChildPosition(int i) const { return 2 * i + 2; }

template<class T>
int HeapPriorityQueue<T>::GetLeftChildPosition(int i) const { return 2 * i + 1; }

template<class T>
int HeapPriorityQueue<T>::GetParentPosition(int i) const { return (i - 1) / 2; }

template<class T>
bool HeapPriorityQueue<T>::HasRightChild(int i) const { return GetRightChildPosition(i) < size; }

template<class T>
bool HeapPriorityQueue<T>::HasLeftChild(int i) const { return GetLeftChildPosition(i) < size; }

template<class T>
bool HeapPriorityQueue<T>::IsRoot(int i) const { return i == 0; }

template<class T>
bool HeapPriorityQueue<T>::IsLeaf(int i) const { return !HasLeftChild(i); }

template<class T>
void HeapPriorityQueue<T>::BubbleDown(int i)
{
    if (!IsLeaf(i))
    {
        int leftChildIndex = GetLeftChildPosition(i);

        int maxIndeks = i;
        if (array[leftChildIndex] > array[maxIndeks]) maxIndeks = leftChildIndex;


        if (HasRightChild(i))
        {
            int rightChildIndex = GetRightChildPosition(i);

            if (array[rightChildIndex] > array[maxIndeks]) maxIndeks = rightChildIndex;
        }

        if (maxIndeks != i)
        {
            std::swap(array[maxIndeks], array[i]);
            BubbleDown(maxIndeks);
        }
    }
}

template<class T>
void HeapPriorityQueue<T>::BubbleUp(int i)
{
    if (!IsRoot(i))
    {
        int parentIndex = GetParentPosition(i);

        if (array[parentIndex] < array[i])
        {
            std::swap(array[parentIndex], array[i]);
            BubbleUp(parentIndex);
        }
    }
}


template<class T>
void HeapPriorityQueue<T>::ExpandQueue()
{
    try
    {
        T* temp = array;
        array = new T[2 * maxSize];

        for (int i = 0; i < maxSize; i++)
            array[i] = temp[i];

        maxSize *= 2;

        delete[] temp;
    }
    catch (std::bad_alloc e)
    {
        std::cout << e.what() << "\n";
    }
}



template<class T>
void HeapPriorityQueue<T>::Add(const T& item)
{
    if (IsFull())
    {
        ExpandQueue();
    }

    array[size] = item;
    BubbleUp(size);
    size++;
}

template<class T>
T HeapPriorityQueue<T>::Remove()
{
    if (IsEmpty()) throw std::exception("The queue is empty");


    T removedItem = array[0];
    array[0] = array[size - 1];

    BubbleDown();
    size--;

    return removedItem;
}


template<class T>
T HeapPriorityQueue<T>::Peek() const
{
    if (IsEmpty()) throw std::exception("The queue is empty");

    return array[0];
}

template<class T>
bool HeapPriorityQueue<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
bool HeapPriorityQueue<T>::IsFull() const
{
    return size == maxSize;
}

template<class T>
int HeapPriorityQueue<T>::Size() const
{
    return size;
}

template<class T>
HeapPriorityQueue<T>::~HeapPriorityQueue()
{
    delete[] array;
    size = 0;
}