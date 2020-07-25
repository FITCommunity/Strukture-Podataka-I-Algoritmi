#pragma once
#include "List.h"
template<class T>
class ArrayList : public List<T>
{
    int size;
    int maxSize;
    T* array;

    void ExpandList();
public:
    ArrayList(int maxSize);

    void Add(const T& item);

    T Remove();

    T Get(int i) const;

    bool IsEmpty() const;

    bool IsFull() const;

    ~ArrayList();
};

