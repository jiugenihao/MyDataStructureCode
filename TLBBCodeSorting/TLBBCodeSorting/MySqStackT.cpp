#include "pch.h"
#include "MySqStackT.h"

template <class T>
MySqStackT<T>::MySqStackT(int size /*= MAX_STACK_SIZE*/)
{
	m_Size  = size < MAX_STACK_SIZE ? MAX_STACK_SIZE : size;
	m_pData = new T[m_Size];
	m_Top   = -1;
}

template <class T>
MySqStackT<T>::~MySqStackT()
{
	SAFE_DELETE_ARRAY(m_pData);
}

template <class T>
void MySqStackT<T>::Clear()
{
	m_Top = -1;
}

template <class T>
bool MySqStackT<T>::IsEmpty()
{
	return (m_Top == -1);
}

template <class T>
bool MySqStackT<T>::IsFull()
{
	return (m_Top == m_Size-1);
}

template <class T>
int MySqStackT<T>::Size()
{
	return (m_Top + 1);
}

template <class T>
void MySqStackT<T>::Push(T value)
{
	if (IsFull())
	{
		T* tmp = m_pData;
		m_pData = new T[m_Size * 2];

		for (int i = 0; i < m_Size; ++i)
			m_pData[i] = tmp[i];

		m_Size *= 2;
		SAFE_DELETE(tmp);
	}

	m_Top++;
	m_pData[m_Top] = value;
}

template <class T>
T MySqStackT<T>::Pop()
{
	if (IsEmpty())
		throw "¶ÑÕ»Îª¿Õ£¡£¡£¡";

	return m_pData[m_Top--];
}

template <class T>
T MySqStackT<T>::GetTop()
{
	if (IsEmpty())
		throw "¶ÑÕ»Îª¿Õ£¡£¡£¡";

	return m_pData[m_Top];
}

template <class T>
void MySqStackT<T>::Print()
{
	cout << "Size:" << m_Top + 1 << endl;
	for (int i = 0; i <= m_Top; ++i)
	{
		cout << m_pData[i] << " ";
	}
	cout << endl;
	//cout << ".........." << endl;
}