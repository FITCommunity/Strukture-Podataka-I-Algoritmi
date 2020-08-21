#pragma once

#include "BinaryTree.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

template<typename T>
class BinaryTreeTraversal
{
    BinaryTreeTraversal() {}

    static void PostOrderRecursive(const BinaryTreeNode<T>& node, LinkedList<T> *list);
    static void InOrderRecursive(const BinaryTreeNode<T>& node, LinkedList<T>* list);
    static void PreOrderRecursive(const BinaryTreeNode<T>& node, LinkedList<T>* list);
public:
    static LinkedList<T>* PostOrderRecursive(const BinaryTree<T>& tree);
    static LinkedList<T>* InOrderRecursive(const BinaryTree<T>& tree);
    static LinkedList<T>* PreOrderRecursive(const BinaryTree<T>& tree);

    static LinkedList<T>* PostOrderIterative(const BinaryTree<T>& tree);
    static LinkedList<T>* InOrderIterative(const BinaryTree<T>& tree);
    static LinkedList<T>* PreOrderIterative(const BinaryTree<T>& tree);

    static LinkedList<T>* BreadthFirstIterative(const BinaryTree<T>& tree);
};

template<typename T>
void BinaryTreeTraversal<T>::PostOrderRecursive(const BinaryTreeNode<T>& node, LinkedList<T>* list)
{
    if (node != nullptr)
    {
        PostOrderRecursive(node->GetLeftChild(), list);
        PostOrderRecursive(node->GetRightChild(), list);
        list->Add(node->GetValue());
    }
}

template<typename T>
void BinaryTreeTraversal<T>::InOrderRecursive(const BinaryTreeNode<T>& node, LinkedList<T>* list)
{
    if (node != nullptr)
    {
        PostOrderRecursive(node->GetLeftChild(), list);
        list->Add(node->GetValue());
        PostOrderRecursive(node->GetRightChild(), list);
    }
}

template<typename T>
void BinaryTreeTraversal<T>::PreOrderRecursive(const BinaryTreeNode<T>& node, LinkedList<T>* list)
{
    if (node != nullptr)
    {
        list->Add(node->GetValue());
        PostOrderRecursive(node->GetLeftChild(), list);
        PostOrderRecursive(node->GetRightChild(), list);
    }
}

template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::PostOrderRecursive(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;
    PostOrderRecursive(tree.GetRoot(), list);
    return list;
}

template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::InOrderRecursive(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;
    InOrderRecursive(tree.GetRoot(), list);
    return list;
}

template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::PreOrderRecursive(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;
    PreOrderRecursive(tree.GetRoot(), list);
    return list;
}


template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::PostOrderIterative(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;
    LinkedStack<T> *stack = new LinkedStack<T>;


    LinkedStack<BinaryTreeNode<T>*> temp;
    temp.Push(tree.GetRoot());

    while (!temp.IsEmpty())
    {
        BinaryTreeNode<T>* node = temp.Pop();
        if (node != nullptr)
        {
            stack->Push(node->GetValue());
            temp.Push(node->GetLeftChild());
            temp.Push(node->GetRightChild());
        }
    }

    while (!stack->IsEmpty())
    {
        list->Add(stack->Pop());
    }

    return list;
}

template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::InOrderIterative(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;

    BinaryTreeNode<T>* current = tree.GetRoot();

    LinkedStack<BinaryTreeNode<T>*> stack;

    while (true)
    {
        if (current != nullptr)
        {
            stack.Push(current);
            current = current->GetLeftChild();
        }
        else
        {
            if (stack.IsEmpty())
                break;

            current = stack.Pop();
            list->Add(current->GetValue());
            current = current->GetRightChild();
        }
    }
    return list;
}

template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::PreOrderIterative(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;

    LinkedStack<BinaryTreeNode<T>*> stack;
    stack.Push(tree.GetRoot());

    while (!stack.IsEmpty())
    {
        BinaryTreeNode<T>* node = stack.Pop();

        list->Add(node->GetValue());

        if (node->GetRightChild() != nullptr)
            stack.Push(node->GetRightChild());

        if (node->GetLeftChild() != nullptr)
            stack.Push(node->GetLeftChild());
    }

    return list;
}

template<typename T>
LinkedList<T>* BinaryTreeTraversal<T>::BreadthFirstIterative(const BinaryTree<T>& tree)
{
    LinkedList<T>* list = new LinkedList<T>;

    LinkedStack<BinaryTreeNode<T>*> queue;
    queue.Push(tree.GetRoot());

    while (!queue.IsEmpty())
    {
        BinaryTreeNode<T>* node = queue.Pop();

        list->Add(node->GetValue());

        if (node->GetRightChild() != nullptr)
            queue.Push(node->GetRightChild());

        if (node->GetLeftChild() != nullptr)
            queue.Push(node->GetLeftChild());
    }

    return list;
}
