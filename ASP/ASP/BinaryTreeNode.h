#pragma once

template<typename T>
class BinaryTreeNode
{
    T Value;
    BinaryTreeNode<T>* LeftChild;
    BinaryTreeNode<T>* RightChild;
public:
    BinaryTreeNode(T value) : Value(value), LeftChild(nullptr), RightChild(nullptr)
    {}

    T GetValue() const { return Value; }
    void SetValue(T value) { Value = value; }

    BinaryTreeNode<T>* GetLeftChild() const { return LeftChild; }
    void SetLeftChild(BinaryTreeNode<T>* child) { LeftChild = child; }


    BinaryTreeNode<T>* GetRightChild() const { return RightChild; }
    void SetRightChild(BinaryTreeNode<T>* child) { RightChild = child; }

};

