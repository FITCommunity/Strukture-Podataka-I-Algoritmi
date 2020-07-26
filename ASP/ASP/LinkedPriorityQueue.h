#pragma once
#include "Queue.h"
#include "Node.h"
template<class T>
class LinkedPriorityQueue : public Queue<T>
{
    Node<T>* head;
public:
    LinkedPriorityQueue();

    void Add(const T& item);

    T Remove();

    T Peek() const;

    bool IsEmpty() const;

    ~LinkedPriorityQueue();
};

