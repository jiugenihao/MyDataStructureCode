#include "pch.h"
#include "MyLinkStackT.h"

template <class T>
MyLinkStackT<T>::MyLinkStackT()
{
	m_pTop = nullptr;
	m_Size = 0;
}

template <class T>
MyLinkStackT<T>::~MyLinkStackT()
{
	Clear();
}

template <class T>
bool MyLinkStackT<T>::IsEmpty()
{
	return (m_pTop == nullptr);
}

template <class T>
void MyLinkStackT<T>::Clear()
{
	LinkListNode<T>*p = m_pTop;
	while (nullptr != p)
	{
		LinkListNode<T>* q = p;
		p = p->m_pNext;
		delete q;
	}
	m_pTop = nullptr;
	m_Size = 0;
}

template <class T>
void MyLinkStackT<T>::Push(T value)
{
	LinkListNode<T>* p = new LinkListNode<T>(value);
	p->m_pNext = m_pTop;
	m_pTop = p;
	m_Size++;
}

template <class T>
T MyLinkStackT<T>::Pop()
{
	if (IsEmpty())
		throw "¶ÑÕ»Îª¿Õ£¡£¡£¡";
	
	LinkListNode<T>* p = m_pTop;
	m_pTop = m_pTop->m_pNext;
	T tmp = p->m_Data;
	delete p;
	m_Size--;

	return tmp;
}

template <class T>
T MyLinkStackT<T>::GetTop()
{
	if (IsEmpty())
		throw "¶ÑÕ»Îª¿Õ£¡£¡£¡";
	
	return m_pTop->m_Data;
}

template <class T>
int MyLinkStackT<T>::Size()
{
	return m_Size;
}

template <class T>
void MyLinkStackT<T>::Print()
{
	cout << "Size:" << m_Size << endl;
	LinkListNode<T>* p = m_pTop;
	while (p)
	{
		cout << p->m_Data << " ";
		p = p->m_pNext;
	}
	cout << endl;
	//cout << ".........." << endl;
}