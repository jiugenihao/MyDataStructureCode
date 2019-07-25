#include "pch.h"
#include "MyDLinkedListT.h"

template <class T>
MyDLinkedListT<T>::MyDLinkedListT()
{
	m_Head = nullptr;
	m_Size = 0;
}

template <class T>
MyDLinkedListT<T>::~MyDLinkedListT()
{
	Clear();
}

template <class T>
bool MyDLinkedListT<T>::IsEmpty()
{
	return (m_Head == nullptr);
	//return (m_Size == 0);
}

template <class T>
int MyDLinkedListT<T>::Size()
{
	int len = 0;
	DLinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		len++;
		p = p->m_pNext;
	}
	
	return len;
	//return m_Size;
}

template <class T>
DLinkListNode<T>* MyDLinkedListT<T>::GetNode(int pos)
{
	if (pos < 0 || IsEmpty())
		return nullptr;

	int i = 0;
	DLinkListNode<T>* p = m_Head;
	while (nullptr != p && i < pos)
	{
		p = p->m_pNext;
		i++;
	}
	return p;
}

template <class T>
bool MyDLinkedListT<T>::Get(int pos, T& value)
{
	DLinkListNode<T>* p = GetNode(pos);
	if (nullptr != p)
	{
		value = p->m_Data;
		return true;
	}
	return false;
}

template <class T>
bool MyDLinkedListT<T>::Set(int pos, T value)
{
	DLinkListNode<T>* p = GetNode(pos);
	if (nullptr != p)
	{
		p->m_Data = value;
		return true;
	}
	return false;
}

template <class T>
void MyDLinkedListT<T>::Clear()
{
	DLinkListNode<T>* p = m_Head;
	while (nullptr != p)
	{
		DLinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}

	m_Head = nullptr;
	//m_Rear = nullptr;
}

// pos=0代表插入头结点
// pos>0 pos结点前插入，跟单链表一样
template <class T>
DLinkListNode<T>* MyDLinkedListT<T>::Insert(int pos, T value)
{
	DLinkListNode<T>* q = new DLinkListNode<T>(value);
	if (!q) return nullptr;

	if (nullptr == m_Head || pos <= 0)
	{
		q->m_pNext = m_Head;
		m_Head = q;
	}
	else
	{
		// 寻找pos-1结点
		int i = 0;
		DLinkListNode<T>* p = m_Head;
		while (nullptr != p->m_pNext && i < pos)
		{
			p = p->m_pNext;
			++i;
		}
		q->m_pNext = p->m_pNext;
		q->m_pPrev = p;

		if (p->m_pNext)
			p->m_pNext->m_pPrev = q;
		p->m_pNext = q;

	}
	//m_Size++;
	return q;
}

// 双链表删除结点，找到本节点即可
template <class T>
bool MyDLinkedListT<T>::Remove(int pos, T& old)
{
	if (IsEmpty() || pos < 0)
		return false;

	DLinkListNode<T>* p = nullptr;
	if (0 == pos)
	{ 
		p = m_Head;
		old = p->m_Data;
		p->m_pNext->m_pPrev = nullptr;
		m_Head = p->m_pNext;
		delete p;
		return true;
	}
	else
	{
		p = GetNode(pos-1);
		if (nullptr != p && nullptr != p->m_pNext)
		{
			DLinkListNode<T>* q = p->m_pNext;
			old = q->m_Data;
			p->m_pNext = q->m_pNext;
			q->m_pNext->m_pPrev = p;
			delete q;
			return true;
		}
	}
	return false;
}

template <class T>
void MyDLinkedListT<T>::Concat(MyDLinkedListT<T>& list)
{
	if (nullptr == m_Head)
	{
		m_Head = list.m_Head;
	}
	else
	{
		DLinkListNode<T>* p = m_Head;
		while (nullptr != p->m_pNext)
		{
			p = p->m_pNext;
		}
		p->m_pNext = list.m_Head;
		list.m_Head->m_pPrev = p;
	}
	list.m_Head = nullptr;
}