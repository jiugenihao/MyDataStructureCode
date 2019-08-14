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
BinaryNode<T>* MyBinarySortTree<T>::RecursiveSearch(T value)
{
   return RecursiveSearch(this->m_pRoot, value);
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::RecursiveSearch(BinaryNode<T>* pNode, T value)
{
    BinaryNode<T>* pFind = nullptr;
    if (!pNode) return nullptr;
    if (value == pNode->m_Data)
    {
        pFind = pNode;
    }
    else if (value < pNode->m_Data)
    {
        pFind = RecursiveSearch(pNode->m_pLeft, value);
    }
    else
    {
        pFind = RecursiveSearch(pNode->m_pRight, value);
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
BinaryNode<T>* MyBinarySortTree<T>::RecursiveInsert(T value)
{
    // 头结点这个容易出错，记住
    if (!this->m_pRoot)
    {
        this->m_pRoot = new BinaryNode<T>(value);
        return this->m_pRoot;
    }
    
    return RecursiveInsert(this->m_pRoot, value);
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::RecursiveInsert(BinaryNode<T>* pNode, T value)
{
    BinaryNode<T>* q = nullptr;
    if (value == pNode->m_Data)
    {
        return nullptr;
    }
    else if (value < pNode->m_Data)
    {
        if (pNode->m_pLeft)
        {
            return RecursiveInsert(pNode->m_pLeft, value);
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
            return RecursiveInsert(pNode->m_pRight, value);
        }
        else
        {
            q = new BinaryNode<T>(value);
            pNode->m_pRight = q;
            return q;
        }
    }
    
    return q;
    
}

template <class T>
BinaryNode<T>* MyBinarySortTree<T>::Insert(T value)
{
    if (this->m_pRoot)
    {
        BinaryNode<T>* p = this->m_pRoot;
        BinaryNode<T>* q = nullptr;
        while (p->m_Data != value)
        {
            if (value < p->m_Data)
            {
                if (p->m_pLeft)
                {
                    p = p->m_pLeft;
                }
                else
                {
                    q = new BinaryNode<T>(value);
                    p->m_pLeft = q;
                }
                
            }
            else
            {
                if (p->m_pRight)
                {
                    p = p->m_pRight;
                }
                else
                {
                    q = new BinaryNode<T>(value);
                    p->m_pRight = q;
                }
                
            }
        }
        
        return q;
    }
    else
    {
        this->m_pRoot = new BinaryNode<T>(value);
        return this->m_pRoot;
    }
}

template <class T>
bool MyBinarySortTree<T>::RecursiveRemove(T value)
{
    return true;
}

template <class T>
bool MyBinarySortTree<T>::RecursiveRemove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent)
{
    return true;
}
