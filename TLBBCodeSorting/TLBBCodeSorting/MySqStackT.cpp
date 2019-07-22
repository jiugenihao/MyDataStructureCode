#include "pch.h"
#include "MySqStackT.h"

template <class T>
MySqStackT<T>::MySqStackT(int size /*= 64*/)
{
	m_Size  = size < 64 ? 64 : size;
	m_pElem = new T[m_Size];
	m_Top   = -1;
}

template <class T>
MySqStackT<T>::~MySqStackT()
{
	SAFE_DELETE_ARRAY(m_pElem);
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
		T* tmp = m_pElem;
		m_pElem = new T[m_Size * 2];

		for (int i = 0; i < m_Size; ++i)
			m_pElem[i] = tmp[i];

		m_Size *= 2;
		SAFE_DELETE(tmp);
	}

	m_Top++;
	m_pElem[m_Top] = value;
}

template <class T>
T MySqStackT<T>::Pop()
{
	if (IsEmpty())
		throw "¶ÑÕ»Îª¿Õ£¡£¡£¡";

	return m_pElem[m_Top--];
}

template <class T>
T MySqStackT<T>::GetTop()
{
	if (IsEmpty())
		throw "¶ÑÕ»Îª¿Õ£¡£¡£¡";

	return m_pElem[m_Top];
}

template <class T>
void MySqStackT<T>::Print()
{
	cout << "Size:" << m_Top + 1 << endl;
	for (int i = 0; i <= m_Top; ++i)
	{
		cout << m_pElem[i] << " ";
	}
	cout << endl;
	cout << ".........." << endl;
}