#pragma once

#include <stdexcept>

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

    bool Remove(const T& item);

    T Get(int i) const;

    bool IsEmpty() const;

    ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() : size(0), head(nullptr)
{
}


template<class T>
void LinkedList<T>::Add(const T& item)
{
    size++;

    Node<T>* newNode = new Node<T>(item, nullptr);

    if (!head)
    {
        head = newNode;
        return;
    }

    Node<T>* beginning = head;
    while (beginning->GetNext()) beginning = beginning->GetNext();
    beginning->GetNext() = newNode;
}

template<class T>
T LinkedList<T>::Remove()
{
    if (IsEmpty()) throw std::exception("The list is empty");

    size--;

    Node<T>* beginning = head;
    Node<T>* beforeBeginning = nullptr;

    while (beginning->GetNext())
    {
        beforeBeginning = beginning;
        beginning = beginning->GetNext();
    }

    if (beforeBeginning) beforeBeginning->GetNext() = nullptr;
    else head = nullptr;

    T removedItem = beginning->GetData();
    delete beginning;
    return removedItem;
}

template<class T>
bool LinkedList<T>::Remove(const T &item)
{
    Node<T>* beginning = head;
    Node<T>* beforeBeginning = nullptr;

    while (beginning)
    {
        if (beginning->GetData() == item) break;

        beforeBeginning = beginning;
        beginning = beginning->GetNext();
    }

    if (!beginning) return false;

    if (!beforeBeginning) head = beginning->GetNext();
    else beforeBeginning->GetNext() = beginning->GetNext();

    delete beginning;
    return true;
}

template<class T>
T LinkedList<T>::Get(int i) const
{
    if (i < 0 || i > size)
    {
        throw std::range_error("Index out of range");
    }

    Node<T>* beginning = head;
    for (int j = 0; j < i; j++)
        beginning = beginning->GetNext();
    return beginning->GetData();
}

template<class T>
bool LinkedList<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    while (head)
    {
        Node<T>* temp = head;
        head = head->GetNext();
        delete temp;
    }
    size = 0;
}