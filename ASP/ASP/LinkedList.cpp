#include "LinkedList.h"
#include <stdexcept>

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
    if (IsEmpty()) return;

    size--;

    Node<T>* beginning = head;
    Node<T>* beforeBeginning = nullptr;

    while (beginning)
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