#include "pch.h"
#include "MyLinkedListT.h"


template <class T>
MySinglyLinkedListT<T>::MySinglyLinkedListT()
{
	m_pHead = nullptr;
//	m_Len = 0;
}

template <class T>
MySinglyLinkedListT<T>::MySinglyLinkedListT(T value[], int n)
{
	m_pHead = nullptr;
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
	return (m_pHead == nullptr);
}

template <class T>
void MySinglyLinkedListT<T>::Clear()
{
	LinkListNode<T>* p = m_pHead;
	while (nullptr != p)
	{
		LinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}
	m_pHead = nullptr;
//	m_Len = 0;
}

// 遍历
template <class T>
int MySinglyLinkedListT<T>::Size()
{
	int len = 0;
	LinkListNode<T>* p = m_pHead;
	while (nullptr != p)
	{
		len++;
		p = p->m_pNext;
	}
	return len;
}

// 当pos大于现有链表长度时，返回的是尾结点
// 用pos做参数对于链表来说，确实不是个好事情，因为链表毕竟不是随机存取的
// 应该以结点为参数，在结点前后插入和删除元素
// pos大于链表长度，会返回nullptr
template <class T>
LinkListNode<T>* MySinglyLinkedListT<T>::GetNode(int pos)
{
	if (pos < 0 || IsEmpty())
		return nullptr;

	int i = 0;
	LinkListNode<T>* p = m_pHead;

	//for (i = 0; i < pos, nullptr! = p; i++)
	//{
	//	p = p->m_pNext;
	//}

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

	if (nullptr == m_pHead || pos <= 0)
	{
		q->m_pNext = m_pHead;
		m_pHead = q;
	}
	else
	{
		// 寻找pos-1结点
		int i = 0;
		LinkListNode<T>* p = m_pHead;
		
		while (nullptr != p->m_pNext && i < pos-1)
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
// pos是空结点，可以进行insert但是不可以delete
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
		p = m_pHead;
		old = p->m_Data;
		m_pHead = m_pHead->m_pNext;
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
	if (nullptr == m_pHead)
	{
		m_pHead = list.m_pHead;
	}
	else
	{
		LinkListNode<T>* p = m_pHead;
		while (nullptr != p->m_pNext)
		{
			p = p->m_pNext;
		}
		p->m_pNext = list.m_pHead;
	}
	list.m_pHead = nullptr;
}

template <class T>
void MySinglyLinkedListT<T>::Visit()
{
	LinkListNode<T>* p = m_pHead;
	while (nullptr != p)
	{
		cout << p->m_Data << endl;
		p = p->m_pNext;
	}
}
