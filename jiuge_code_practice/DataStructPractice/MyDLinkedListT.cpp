#include "pch.h"
#include "MyDLinkedListT.h"

template <class T>
MyDLinkedListT<T>::MyDLinkedListT()
{
	m_pHead = nullptr;
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
	return (m_pHead == nullptr);
	//return (m_Size == 0);
}

template <class T>
int MyDLinkedListT<T>::Size()
{
	int len = 0;
	DLinkListNode<T>* p = m_pHead;
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
	DLinkListNode<T>* p = m_pHead;
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
	DLinkListNode<T>* p = m_pHead;
	while (nullptr != p)
	{
		DLinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}

	m_pHead = nullptr;
	//m_Rear = nullptr;
}

// pos=0�������ͷ���
// pos>0 pos���ǰ���룬��������һ��
template <class T>
DLinkListNode<T>* MyDLinkedListT<T>::Insert(int pos, T value)
{
	DLinkListNode<T>* q = new DLinkListNode<T>(value);
	if (!q) return nullptr;

	if (nullptr == m_pHead || pos <= 0)
	{
		q->m_pNext = m_pHead;
		m_pHead = q;
	}
	else
	{
		// Ѱ��pos-1���
		int i = 0;
		DLinkListNode<T>* p = m_pHead;
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

// ˫����ɾ����㣬�ҵ����ڵ㼴��
template <class T>
bool MyDLinkedListT<T>::Remove(int pos, T& old)
{
	if (IsEmpty() || pos < 0)
		return false;

	DLinkListNode<T>* p = nullptr;
	if (0 == pos)
	{ 
		p = m_pHead;
		old = p->m_Data;
		p->m_pNext->m_pPrev = nullptr;
		m_pHead = p->m_pNext;
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
	if (nullptr == m_pHead)
	{
		m_pHead = list.m_pHead;
	}
	else
	{
		DLinkListNode<T>* p = m_pHead;
		while (nullptr != p->m_pNext)
		{
			p = p->m_pNext;
		}
		p->m_pNext = list.m_pHead;
		list.m_pHead->m_pPrev = p;
	}
	list.m_pHead = nullptr;
}