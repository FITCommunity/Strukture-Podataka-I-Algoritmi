#pragma once
#include "Stack.h"
#include "Node.h"
template<class T>
class LinkedStack : public Stack<T>
{
    int size;
    Node<T>* head;
public:
    LinkedStack();

    void Push(const T& item);

    T Pop();

    T Top() const;

    bool IsEmpty() const;

    ~LinkedStack();
};

