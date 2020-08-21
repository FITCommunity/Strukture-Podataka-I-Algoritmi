#pragma once

#include <iostream>
#include <stdexcept>

#include "Stack.h"
template<class T>
class ArrayStack : public Stack<T>
{
    int size;
    int maxSize;
    T* array;

    void ExpandStack();
public:
    ArrayStack(int maxSize);

    void Push(const T& item);

    T Pop();

    T Top() const;

    bool IsEmpty() const;

    bool IsFull() const;

    ~ArrayStack();
};

template<class T>
ArrayStack<T>::ArrayStack(int maxSize) : size(0), maxSize(maxSize), array(nullptr)
{}

template<class T>
void ArrayStack<T>::ExpandStack()
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
void ArrayStack<T>::Push(const T& item)
{
    if (IsFull())
    {
        ExpandStack();
    }

    array[size++] = item;
}

template<class T>
T ArrayStack<T>::Pop()
{
    if (IsEmpty()) return;

    T removedItem = array[size - 1];
    size--;
    return removedItem;
}

template<class T>
T ArrayStack<T>::Top() const
{
    if (IsEmpty()) return;

    return array[size - 1];
}

template<class T>
bool ArrayStack<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
bool ArrayStack<T>::IsFull() const
{
    return size == maxSize;
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    delete[] array;
    size = 0;
}