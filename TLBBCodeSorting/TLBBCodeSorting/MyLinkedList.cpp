#include "pch.h"
#include "MyLinkedList.h"


template <class T>
MySinglyLinkedList<T>::MySinglyLinkedList()
{
	m_Head = nullptr;
	m_Len = 0;
}

template <class T>
MySinglyLinkedList<T>::MySinglyLinkedList(T value[], int n)
{
	m_Head = nullptr;
	if (n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			Insert(i, value[i]);
		}
	}
}

template <class T>
MySinglyLinkedList<T>::~MySinglyLinkedList()
{
	Clear();
}

template <class T>
bool MySinglyLinkedList<T>::IsEmpty()
{
	return (m_Head == nullptr);
}

template <class T>
void MySinglyLinkedList<T>::Clear()
{
	LinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		LinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}
	m_Head = nullptr;
	m_Len = 0;
}

template <class T>
int MySinglyLinkedList<T>::Len()
{
	int len = 0;
	LinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		len++;
		p = p->m_pNext;
	}
	return len;
}

template <class T>
LinkListNode<T>* MySinglyLinkedList<T>::GetNode(int pos)
{
	if (pos < 0 || IsEmpty())
		return nullptr;

	int i = 0;
	LinkListNode<T>* p = m_Head;
	while (nullptr != p && i < pos)
	{
		p = p->m_pNext;
		i++;
	}
	return p;
}

template <class T>
bool MySinglyLinkedList<T>::Get(int pos, T& value)
{
	LinkListNode<T>* p = GetNode(pos);
	if (nullptr != p)
	{
		value = p->m_Data;
		return true;
	}
	return false;
}

template <class T>
bool MySinglyLinkedList<T>::Set(int pos, T value)
{
	LinkListNode<T>* p = GetNode(pos);
	if (nullptr != p)
	{
		p->m_Data = value;
		return true;
	}
	return false;
}

// pos位置插入新节点q，需要知道pos-1位置的结点情况
// 1.空表，无pos-1结点
// 2.非空表，找到pos-1位置结点p:
template <class T>
LinkListNode<T>* MySinglyLinkedList<T>::Insert(int pos, T value)
{
	LinkListNode<T>* q = new LinkListNode<T>(value);
	if (nullptr == m_Head || pos <= 0)
	{
		q->m_pNext = m_Head;
		m_Head = q;
	}
	else
	{
		int i = 1;
		LinkListNode<T>* p = m_Head;
		while (nullptr != p->m_pNext && i < pos)
		{
			p = p->m_pNext;
			++i;
		}
		q->m_pNext = p->m_pNext;
		p->m_pNext = q;
	}

	m_Len++;
	return q;
}



template <class T>
bool MySinglyLinkedList<T>::Remove(int pos, T& old)
{
	LinkListNode<T>* p = GetNode(pos);
	if (nullptr != p)
	{
		old = p->m_Data;
		delete p;
		return true;
	}
	return false;
}

template <class T>
void MySinglyLinkedList<T>::Visit()
{
	LinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		//cout << p->m_Data << endl;
		p = p->m_pNext;
	}
}
