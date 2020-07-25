#pragma once
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

