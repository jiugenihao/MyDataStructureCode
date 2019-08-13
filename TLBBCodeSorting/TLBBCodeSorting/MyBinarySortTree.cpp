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
BinaryNode<T>* MyBinarySortTree<T>::RSearch(T value)
{
   return Search(this->m_pRoot, value);
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Search(BinaryNode<T>* pNode, T value)
{
    BinaryNode<T>* pFind = nullptr;
    if (!pNode) return nullptr;
    if (value == pNode->m_Data)
    {
        pFind = pNode;
    }
    else if (value < pNode->m_Data)
    {
        pFind = Search(pNode->m_pLeft);
    }
    else
    {
        pFind = Search(pNode->m_pRight);
    }
    
    return pFind;
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Search(T value)
{
    BinaryNode<T>* p = this->m_pRoot;

    while (p)
    {
        if (p->m_Data == value)
        {
            return p;
        }
        else if (p->m_Data > value)
        {
            p = p->m_pLeft;
        }
        else
        {
            p = p->m_pRight;
        }
        
    }
    
    return nullptr;
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::RInsert(T value)
{
    // 头结点这个容易出错，记住
    if (!this->m_pRoot)
    {
        this->m_pRoot = new BinaryNode<T>(value);
        return this->m_pRoot;
    }
    
    return Insert(this->m_pRoot, value);
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Insert(BinaryNode<T>* pNode, T value)
{
    BinaryNode<T>* q = nullptr;
    if (pNode)
    {
        if (value == pNode->m_Data)
        {
            return nullptr;
        }
        else if (value < pNode->m_Data)
        {
            if (pNode->m_pLeft)
            {
                return Insert(pNode->m_pLeft, value);
            }
            else
            {
                q = new BinaryNode<T>(value);
                pNode->m_pLeft = q;
                return q;
            }
        }
        else
        {
            if (pNode->m_pRight)
            {
                return Insert(pNode->m_pRight, value);
            }
            else
            {
                q = new BinaryNode<T>(value);
                pNode->m_pRight = q;
                return q;
            }
        }
    }
    
    return q;
    
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
bool MyBinarySortTree<T>::Remove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent)
{
    return true;
}
