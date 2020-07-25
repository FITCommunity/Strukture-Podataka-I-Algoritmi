#include "LinkedQueue.h"
#include <stdexcept>

template<class T>
LinkedQueue<T>::LinkedQueue() : first(nullptr), last(nullptr)
{}



template<class T>
void LinkedQueue<T>::Add(const T& item)
{
    Node<T>* newNode = new Node<T>(item, nullptr);

    if (IsEmpty()) first = newNode;
    else last->GetNext() = newNode;

    last = newNode;
}

template<class T>
T LinkedQueue<T>::Remove()
{
    if (IsEmpty()) return;

    Node<T>* tempNode = first;
    first = first->GetNext();

    if (IsEmpty()) last = nullptr;

    T removedItem = tempNode->GetData();
    delete tempNode;
    return removedItem;
}


template<class T>
T LinkedQueue<T>::Peek() const
{
    if (IsEmpty()) return;

    return first->GetData();
}

template<class T>
bool LinkedQueue<T>::IsEmpty() const
{
    return first == nullptr;
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
    while (first)
    {
        Node<T>* temp = first;
        first = first->GetNext();
        delete temp;
    }
}