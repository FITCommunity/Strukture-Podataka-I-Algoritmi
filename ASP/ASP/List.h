#pragma once
template<class T>
class List
{
public:
    virtual void Add(const T& item) = 0;
    virtual T Remove() = 0;
    virtual T Get(int i) const = 0;
    virtual bool IsEmpty() const = 0;
};

