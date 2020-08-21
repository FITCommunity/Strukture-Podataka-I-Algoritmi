#pragma once

#include "BinaryTreeNode.h"

template<typename T>
class BinaryTree
{
    BinaryTreeNode<T>* root;
    void Add(BinaryTreeNode<T>* node, const T &value);
    BinaryTreeNode<T>* Get(BinaryTreeNode<T>* node, const T &value) const;
    void Dispose(BinaryTreeNode<T>* node);


public:
    BinaryTree() : root(nullptr) {}
    void Add(const T &value);
    BinaryTreeNode<T>* Get(const T &value) const;
    ~BinaryTree();
};



template<typename T>
void BinaryTree<T>::Add(BinaryTreeNode<T>* node, const T& value)
{
	if (node == nullptr)
	{
		root = new BinaryTreeNode<T>(value);
	}
	else if (node->GetValue() > value)
	{
        Add(node->GetLeftChild(), value);
	}
	else if(node->GetValue() < value)
	{
        Add(node->GetRightChild(), value);
	}

    return;
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Get(BinaryTreeNode<T>* node, const T& value) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    else if (node->GetValue() > value)
    {
        return Get(node->GetLeftChild(), value);
    }
    else if(node->GetValue() > value)
    {
        return Get(node->GetRightChild(), value);
    }
    else
    {
        return node;
    }
}

template<typename T>
void BinaryTree<T>::Dispose(BinaryTreeNode<T>* node)
{
    if (node != nullptr)
    {
        Dispose(node->GetRightChild());
        Dispose(node->GetLeftChild());
        delete node; node = nullptr;
    }
}

template<typename T>
void BinaryTree<T>::Add(const T& value)
{
    Add(root, value);
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Get(const T& value) const
{
    return Get(root, value);
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    Dispose(root);
}
