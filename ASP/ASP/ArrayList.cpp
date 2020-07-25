#include <iostream>
#include <stdexcept>

#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList(int maxSize) : size(0), maxSize(maxSize), array(nullptr)
{
}

template<class T>
void ArrayList<T>::ExpandList()
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
void ArrayList<T>::Add(const T& item)
{
    if (IsFull())
    {
        ExpandList();
    }

    array[size++] = item;
}

template<class T>
T ArrayList<T>::Remove()
{
    if (IsEmpty()) return;

    T removedItem = array[size - 1];
    size--;
    return removedItem;
}

template<class T>
T ArrayList<T>::Get(int i) const
{
    if (i < 0 || i > size)
    {
        throw std::range_error("Index out of range");
    }

    return array[i];
}

template<class T>
bool ArrayList<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
bool ArrayList<T>::IsFull() const
{
    return size == maxSize;
}

template<class T>
ArrayList<T>::~ArrayList()
{
    delete[] array;
    size = 0;
}