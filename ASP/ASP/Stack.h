#pragma once
template<class T>
class Stack
{
public:
    virtual void Push(const T& item) = 0;
    virtual T Pop() = 0;
    virtual T Top() const = 0;
    virtual bool IsEmpty() const = 0;
};

