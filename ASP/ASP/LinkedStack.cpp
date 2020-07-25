#include "LinkedStack.h"
#include <stdexcept>


template<class T>
LinkedStack<T>::LinkedStack() : size(0), head(nullptr)
{}


template<class T>
void LinkedStack<T>::Push(const T& item)
{
    Node<T>* newNode = new Node<T>(item, head);
    head = newNode;
}

template<class T>
T LinkedStack<T>::Pop()
{
    if (IsEmpty()) return;

    Node<T>* tempNode = head;
    head = head->GetNext();

    T removedItem = tempNode->GetData();
    delete tempNode;
    return removedItem;
}

template<class T>
T LinkedStack<T>::Top() const
{
    if (IsEmpty()) return;

    return head->GetData();
}

template<class T>
bool LinkedStack<T>::IsEmpty() const
{
    return size == 0;
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
    while (head)
    {
        Node<T>* temp = head;
        head = head->GetNext();
        delete temp;
    }
    size = 0;
}