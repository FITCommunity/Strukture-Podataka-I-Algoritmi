#pragma once
#include "Queue.h"
#include "Node.h"
template<class T>
class LinkedQueue : public Queue<T>
{
    Node<T>* first;
    Node<T>* last;
public:
    LinkedQueue();

    void Add(const T& item);

    T Remove();

    T Peek() const;

    bool IsEmpty() const;

    ~LinkedQueue();
};

