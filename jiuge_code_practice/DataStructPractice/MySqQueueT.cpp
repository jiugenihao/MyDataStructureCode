#include "pch.h"
#include "MySqQueueT.h"

template <class T>
MySqQueueT<T>::MySqQueueT(int size /*= MAX_SQQUEUE_SIZE*/)
{
	m_Size = size < MAX_SQQUEUE_SIZE ? MAX_SQQUEUE_SIZE : size;
	m_pData = new T[m_Size];
	m_Head = m_Tail = 0;
}

template <class T>
MySqQueueT<T>::~MySqQueueT()
{
	SAFE_DELETE_ARRAY(m_pData);
}

template <class T>
bool MySqQueueT<T>::IsEmpty()
{
	return (m_Head == m_Tail);
}

template <class T>
bool MySqQueueT<T>::IsFull()
{
	return (m_Head == (m_Tail + 1) % m_Size);
}

template <class T>
int MySqQueueT<T>::Size()
{
	if (m_Tail >= m_Head)
	{
		return (m_Tail - m_Head);
	}
	else
	{
		return (m_Tail + m_Size - m_Head);
	}
}

template <class T>
T MySqQueueT<T>::GetHead()
{
	if (IsEmpty())
		throw "The Queue Is NULL !!!";
	return m_pData[m_Head];
}

template <class T>
T MySqQueueT<T>::GetTail()
{
	if (IsEmpty())
		throw "The Queue Is NULL !!!";
	return m_pData[m_Tail - 1];
}

template <class T>
void MySqQueueT<T>::EnQueue(T value)
{
	if (IsFull())
	{
		T* tmp = m_pData;
		m_pData = new T[m_Size * 2];
		
		int i = m_Head;
		int j = 0;
		while (i != m_Tail)
		{
			m_pData[j] = tmp[i];
			i = (i + 1) % m_Size;
			j++;
		}
		m_Head = 0;
		m_Tail = j;
		m_Size *= 2;
		SAFE_DELETE(tmp);
	}
	
	m_pData[m_Tail] = value;
	m_Tail = (m_Tail + 1) % m_Size;
}

template <class T>
T MySqQueueT<T>::DeQueue()
{
	if (IsEmpty())
		throw "The Queue Is NULL !!!";

	T tmp = m_pData[m_Head];
	m_Head = (m_Head + 1) % m_Size;
	return tmp;
}