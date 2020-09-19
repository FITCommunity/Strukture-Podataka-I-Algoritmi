#pragma once
#include <stdexcept>
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

template<class T>
LinkedPriorityQueue<T>::LinkedPriorityQueue() : head(nullptr)
{}



template<class T>
void LinkedPriorityQueue<T>::Add(const T& item)
{
    Node<T>* beginning = head;
    Node<T>* beforeBeginning = nullptr;

    while (head)
    {
        if (beginning->GetData() < item) break;

        beforeBeginning = beginning;
        beginning = beginning->GetNext();
    }

    Node<T>* newNode = new Node<T>(item, beginning);

    beforeBeginning ? beforeBeginning->GetNext() = newNode
                    : head = newNode;
}

template<class T>
T LinkedPriorityQueue<T>::Remove()
{
    if (IsEmpty()) throw std::exception("The queue is empty");

    Node<T>* tempNode = head;
    head = head->GetNext();

    T temp = tempNode->GetData();
    delete tempNode;
    return temp;
}


template<class T>
T LinkedPriorityQueue<T>::Peek() const
{
    if (IsEmpty()) throw std::exception("The queue is empty");

    return head->GetData();
}

template<class T>
bool LinkedPriorityQueue<T>::IsEmpty() const
{
    return head == nullptr;
}


template<class T>
LinkedPriorityQueue<T>::~LinkedPriorityQueue()
{
    while (head)
    {
        Node<T>* temp = head;
        head = head->GetNext();
        delete temp;
    }
}