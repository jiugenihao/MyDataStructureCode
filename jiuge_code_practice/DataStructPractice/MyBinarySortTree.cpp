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
	return this->m_pRoot && RecursiveRemove(value, this->m_pRoot, nullptr);    
}

template <class T>
bool MyBinarySortTree<T>::RecursiveRemove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent)
{
	if (pNode)
	{
		if (value < pNode->m_Data)
		{
			return RecursiveRemove(value, pNode->m_pLeft, pNode);
		}
		else if (value > pNode->m_Data)
		{
			return RecursiveRemove(value, pNode->m_pRight, pNode);
		}
		else
		{
			if (pNode->m_pLeft && pNode->m_pRight)
			{
				// pNode是2度结点，不直接删除pNode结点，
				// 而是先寻找pNode在中根序列中的后继结点pInNext，
				// 用pInNext的值替换pNode结点的值，再删除pInNext的结点，
				// 这样就将2度结点的问题转化为1度结点或者叶子结点的问题来处理
				BinaryNode<T>* pInNext = pNode->m_pRight;
				while (pInNext->m_pLeft)
				{
					pInNext = pInNext->m_pLeft;
				}
				// 用后继结点pInNext的值替换pNode的值
				pNode->m_Data = pInNext->m_Data;
				return RecursiveRemove(pNode->m_Data, pNode->m_pRight, pNode);
			}
			else
			{
				// 1度或0度结点
				if (!pParent)   // pNode==m_pRoot
				{
					if (pNode->m_pLeft)
					{
						this->m_pRoot = pNode->m_pLeft;
					}
					else
					{
						this->m_pRoot = pNode->m_pRight;
					}
					return true;
				}
				
				if (pNode == pParent->m_pLeft)
				{
					if (pNode->m_pLeft)
					{
						pParent->m_pLeft = pNode->m_pLeft;
					}
					else
					{
						pParent->m_pLeft = pNode->m_pRight;
					}
					
				}
				else
				{
					if (pNode->m_pLeft)
					{
						pParent->m_pRight = pNode->m_pLeft;
					}
					else
					{
						pParent->m_pRight = pNode->m_pRight;
					}
				}
				return true;
			}
			
		}
	}
	
	return false;
}
