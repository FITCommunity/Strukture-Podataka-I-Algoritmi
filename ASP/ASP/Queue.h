#pragma once
template<class T>
class Queue
{
public:
    virtual void Add(const T& item) = 0;
    virtual T Remove() = 0;
    virtual T Peek() const = 0;
    virtual bool IsEmpty() const = 0;
};

