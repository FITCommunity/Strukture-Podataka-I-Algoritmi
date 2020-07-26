#include <iostream>
#include <stdexcept>

#include "ArrayPriorityQueue.h"

template<class T>
ArrayPriorityQueue<T>::ArrayPriorityQueue(int maxSize) : size(0), maxSize(maxSize), array(nullptr)
{}

template<class T>
void ArrayPriorityQueue<T>::ExpandQueue()
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
int ArrayPriorityQueue<T>::GetFirstElementPosition() const
{
    int max = 0;
    for (int i = 1; i < size; i++)
        if (array[i] > array[max])
            max = i;
    return max;
}

template<class T>
void ArrayPriorityQueue<T>::Add(const T& item)
{
    if (IsFull())
    {
        ExpandQueue();
    }

    array[size++] = item;
}

template<class T>
T ArrayPriorityQueue<T>::Remove()
{
    if (IsEmpty()) return;


    int max = GetFirstElementPosition();

    T removedItem = array[max];
    array[max] = array[size - 1];
    size--;

    return removedItem;
}


template<class T>
T ArrayPriorityQueue<T>::Peek() const
{
    if (IsEmpty()) return;

    int max = GetFirstElementPosition();
    return array[max];
}

template<class T>
bool ArrayPriorityQueue<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
bool ArrayPriorityQueue<T>::IsFull() const
{
    return size == maxSize;
}

template<class T>
ArrayPriorityQueue<T>::~ArrayPriorityQueue()
{
    delete[] array;
    size = 0;
}