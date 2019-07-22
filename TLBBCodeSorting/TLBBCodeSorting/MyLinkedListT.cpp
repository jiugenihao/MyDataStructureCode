#include "pch.h"
#include "MyLinkedListT.h"


template <class T>
MySinglyLinkedListT<T>::MySinglyLinkedListT()
{
	m_Head = nullptr;
//	m_Len = 0;
}

template <class T>
MySinglyLinkedListT<T>::MySinglyLinkedListT(T value[], int n)
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
MySinglyLinkedListT<T>::~MySinglyLinkedListT()
{
	Clear();
}

template <class T>
bool MySinglyLinkedListT<T>::IsEmpty()
{
	return (m_Head == nullptr);
}

template <class T>
void MySinglyLinkedListT<T>::Clear()
{
	LinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		LinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}
	m_Head = nullptr;
//	m_Len = 0;
}

template <class T>
int MySinglyLinkedListT<T>::Size()
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
LinkListNode<T>* MySinglyLinkedListT<T>::GetNode(int pos)
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
bool MySinglyLinkedListT<T>::Get(int pos, T& value)
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
bool MySinglyLinkedListT<T>::Set(int pos, T value)
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
LinkListNode<T>* MySinglyLinkedListT<T>::Insert(int pos, T value)
{
	LinkListNode<T>* q = new LinkListNode<T>(value);
	if (!q) return nullptr;

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

//	m_Len++;
	return q;
}


// 单链表删除，需要找到前一个结点来删除本结点
template <class T>
bool MySinglyLinkedListT<T>::Remove(int pos, T& old)
{
	// 空链表判断
	if (IsEmpty() || pos < 0)
	{
		return false;
	}
	
	LinkListNode<T>* p = nullptr;
	if (pos == 0)
	{
		p = m_Head;
		old = p->m_Data;
		m_Head = m_Head->m_pNext;
		delete p;
		return true;
	}
	else
	{
		p = GetNode(pos - 1);
		if (nullptr != p && nullptr != p->m_pNext)
		{
			LinkListNode<T>* q = p->m_pNext;
			old = q->m_Data;
			p->m_pNext = q->m_pNext;
			delete q;
			return true;
		}
	}
	return false;
}

template <class T>
void MySinglyLinkedListT<T>::Concat(MySinglyLinkedListT<T>& list)
{
	if (nullptr == m_Head)
	{
		m_Head = list.m_Head;
	}
	else
	{
		LinkListNode<T>* p = m_Head;
		while (nullptr != p)
		{
			p = p->m_pNext;
		}
		p->m_pNext = list.m_Head;
	}
	list.m_Head = nullptr;
}

template <class T>
void MySinglyLinkedListT<T>::Visit()
{
	LinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		cout << p->m_Data << endl;
		p = p->m_pNext;
	}
}
