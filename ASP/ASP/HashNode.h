#pragma once

template<typename TKey, typename TValue>
class HashNode
{
    TKey Key;
    TValue Value;
public:
    HashNode(TKey Key, TValue Value) : Key(Key), Value(Value)
    {}

    TKey GetKey() const { return Key; }

    TValue GetValue() const { return Value; }
    void SetValue(TValue value) { Value = value; }
};

