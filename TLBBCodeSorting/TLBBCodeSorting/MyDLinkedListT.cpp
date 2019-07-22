#include "pch.h"
#include "MyDLinkedListT.h"

template <class T>
MyDLinkedListT<T>::MyDLinkedListT()
{
	m_Head = m_Rear = nullptr;
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
}

template <class T>
void MyDLinkedListT<T>::Clear()
{

}