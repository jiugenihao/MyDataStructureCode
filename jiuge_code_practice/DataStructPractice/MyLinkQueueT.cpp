#include "pch.h"
#include "MyLinkQueueT.h"

template <class T>
MyLinkQueueT<T>::MyLinkQueueT()
{
	m_pHead = nullptr;
	m_pTail = nullptr;
}

template <class T>
MyLinkQueueT<T>::~MyLinkQueueT()
{
	Clear();
}

template <class T>
bool MyLinkQueueT<T>::IsEmpty()
{
	return (nullptr == m_pHead && nullptr == m_pTail);
}

template <class T>
int MyLinkQueueT<T>::Size()
{
	int size = 0;
	LinkListNode<T>* p = m_pHead;
	while (p)
	{
		size++;
		p = p->m_pNext;
	}
	return size;
}

template <class T>
void MyLinkQueueT<T>::Clear()
{
	LinkListNode<T>* p = m_pHead;
	while (p)
	{
		LinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}
	m_pHead = m_pTail = nullptr;
}

template <class T>
void MyLinkQueueT<T>::EnQueue(T value)
{
	LinkListNode<T>* p = new LinkListNode<T>(value);
	if (p)
	{
		if (IsEmpty())
		{
			m_pHead = p;
		}
		else
		{
			m_pTail->m_pNext = p;
		}
		m_pTail = p;
	}
}

template <class T>
T MyLinkQueueT<T>::DeQueue()
{
	if (IsEmpty())
		throw "The Queue is NULL !!!";

	LinkListNode<T>* p = m_pHead;
	T tmp = p->m_Data;
	m_pHead = m_pHead->m_pNext;
	delete p;

	if (!m_pHead)
	{
		m_pTail = nullptr;
	}

	return tmp;
}