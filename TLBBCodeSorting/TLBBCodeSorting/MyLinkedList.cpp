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
{}

template <class T>
MySinglyLinkedList<T>::~MySinglyLinkedList()
{
	SAFE_DELETE_ARRAY(m_Head);
}

template <class T>
bool MySinglyLinkedList<T>::IsEmpty()
{
	return (m_Head == nullptr);
}

template <class T>
void MySinglyLinkedList<T>::Clear()
{
	
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

template <class T>
LinkListNode<T>* MySinglyLinkedList<T>::Insert(int pos, T value)
{
	return nullptr;
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
