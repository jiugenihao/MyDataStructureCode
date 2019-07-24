#include "pch.h"
#include "MySqQueueT.h"

template <class T>
MySqQueueT<T>::MySqQueueT(int size /*= MAX_QUEUE_SIZE*/)
{
	m_Size = size < MAX_QUEUE_SIZE ? MAX_QUEUE_SIZE : size;
	m_Data = new T[m_Size];
	m_Head = m_Tail = 0;
}

template <class T>
MySqQueueT<T>::~MySqQueueT()
{
	SAFE_DELETE_ARRAY(m_Data);
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
	return m_Data[m_Head];
}

template <class T>
T MySqQueueT<T>::GetTail()
{
	if (IsEmpty())
		throw "The Queue Is NULL !!!";
	return m_Data[m_Tail - 1];
}

template <class T>
void MySqQueueT<T>::EnQueue(T value)
{
	if (IsFull())
	{
		T* tmp = m_Data;
		m_Data = new T[m_Size * 2];
		
		int i = m_Head;
		int j = 0;
		while (i != m_Tail)
		{
			m_Data[j] = tmp[i];
			i = (i + 1) % m_Size;
			j++;
		}
		m_Head = 0;
		m_Tail = j;
		m_Size *= 2;
		SAFE_DELETE(tmp);
	}
	
	m_Data[m_Tail] = value;
	m_Tail = (m_Tail + 1) % m_Size;
}

template <class T>
T MySqQueueT<T>::DeQueue()
{
	if (IsEmpty())
		throw "The Queue Is NULL !!!";

	T tmp = m_Data[m_Head];
	m_Head = (m_Head + 1) % m_Size;
	return tmp;
}