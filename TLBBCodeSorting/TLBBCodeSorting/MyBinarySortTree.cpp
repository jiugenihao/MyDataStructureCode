#include "pch.h"
#include "MyBinarySortTree.h"

template <class T>
MyBinarySortTree<T>::MyBinarySortTree() : MyBinaryTreeT<T>()
{
}


template <class T>
MyBinarySortTree<T>::~MyBinarySortTree()
{
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Search(T value)
{
    return nullptr;
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Insert(T value)
{
    return nullptr;
}

template <class T>
bool MyBinarySortTree<T>::Remove(T value)
{
    return true;
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Insert(BinaryNode<T>* pNode, T value)
{
    return nullptr;
}

template <class T>
bool MyBinarySortTree<T>::Remove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent)
{
    return true;
}
