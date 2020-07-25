#include "ArrayQueue.h"
#include <stdexcept>

template<class T>
ArrayQueue<T>::ArrayQueue(int maxSize) : size(0), maxSize(maxSize), first(0), last(0), array(nullptr)
{}

template<class T>
void ArrayQueue<T>::ExpandQueue()
{
    try
    {
        T* temp = array;
        array = new T[2 * maxVelicina];

        for (int j = 0, i = first; j < size; j++, i++)
        {
            array[j] = temp[i];

            if (i == maxSize) i = 0;
        }

        first = 0;
        last = size;
        maxSize *= 2;

        delete[] temp;
    }
    catch (std::bad_alloc e)
    {
        std::cout << e.what() << "\n";
    }
}

template<class T>
void ArrayQueue<T>::Add(const T& item)
{
    if (size == maxSize)
    {
        ExpandQueue();
    }

    array[last++] = item;
    if (last == maxSize) last = 0;
    size++;
}

template<class T>
T ArrayQueue<T>::Remove()
{
    T removedItem = array[pocetak++];
    if (first == maxSize) first = 0;
    size--;

    return removedItem;
}


template<class T>
T ArrayQueue<T>::Peek() const
{
    if (IsEmpty()) return;

    return array[first];
}

template<class T>
bool ArrayQueue<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
ArrayQueue<T>::~ArrayQueue()
{
    delete[] array;
    size = 0;
}