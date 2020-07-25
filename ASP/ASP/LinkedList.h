#pragma once
#include "List.h"
#include "Node.h"
template<class T>
class LinkedList : public List<T>
{
    int size;
    Node<T>* head;
public:
    LinkedList();

    void Add(const T& item);

    T Remove();

    T Get(int i) const;

    bool IsEmpty() const;

    ~LinkedList();
};

