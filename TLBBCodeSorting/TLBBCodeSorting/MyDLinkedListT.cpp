#include "pch.h"
#include "MyDLinkedListT.h"

template <class T>
MyDLinkedListT<T>::MyDLinkedListT()
{
	m_Head = m_Rear = nullptr;
	//m_Size = 0;
}

template <class T>
MyDLinkedListT<T>::~MyDLinkedListT()
{
	Clear();
}

template <class T>
bool MyDLinkedListT<T>::IsEmpty()
{
	return (m_Head == nullptr && m_Rear == nullptr);
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
	m_Rear = nullptr;
}

template <class T>
DLinkListNode<T>* MyDLinkedListT<T>::Insert(int pos, T value)
{
	DLinkListNode<T>* q = new DLinkListNode<T>(value);
	if (!q) return nullptr;

	if (IsEmpty() || pos <= 0)
	{
		q->m_pNext = nullptr;
		q->m_pPrev = nullptr;
		m_Head = q;
	}
	else
	{
		int i = 1;
		DLinkListNode<T>* p = m_Head;
		while (nullptr != p->m_pNext && i < pos)
		{
			i++;
			p = p->m_pNext;
		}
		q->m_pPrev = p->m_pPrev;
		p->m_pPrev->m_pNext = q;
		q->m_pNext = p;
		p->m_pPrev = q;
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
		p = GetNode(pos);
		if (nullptr != p)
		{
			old = p;
			p->m_pPrev->m_pNext = p->m_pNext;
			p->m_pNext->m_pPrev = p->m_pPrev;
			delete p;
			return true;
		}
	}
	return false;
}

template <class T>
void MyDLinkedListT<T>::Concat(MyDLinkedListT<T>& list)
{

}