#pragma once
template<class T>
class Node
{
    T data;
    Node<T>* next;
public:
    Node(T data, Node<T> *next) : data(data), next(next)
    {}

    T GetData() const { return data; }
    void SetData(const T& data) { this->data = data; }

    Node<T> *&GetNext() { return next; }
    void SetNext(Node<T>* next) { this->next = next; }
};

