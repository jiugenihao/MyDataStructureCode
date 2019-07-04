#include "pch.h"
#include "MyStack.h"
#include "BaseDefine.h"

MyStack::MyStack(int maxSize):m_MaxSize(maxSize)
{
	m_pData = new StackItem[m_MaxSize];
	for (int i = 0; i < m_MaxSize; ++i)
	{
		m_pData[i].nData = 0;
		//m_pData[i].bUsed = false;
	}
	m_Top = 0;
	//m_Size = 0;
}


MyStack::~MyStack()
{
	SAFE_DELETE_ARRAY(m_pData);
}

bool MyStack::IsFull()
{
	return m_Top >= m_MaxSize;
}
bool MyStack::IsEmpty()
{
	return (m_Top == 0);
}
bool MyStack::Push(int value)
{
	if (IsFull())
	{
		return false;
	}
	
	m_pData[m_Top].nData = value;
	m_Top++;

	return true;
}

int MyStack::Pop()
{
	if (IsEmpty())
	{
		return 0;
	}
	
	int tmp = m_pData[m_Top-1].nData;
	m_Top--;

	return tmp;
}

int MyStack::GetTop()
{
	if (IsEmpty())
	{
		return 0;
	}
	return m_pData[m_Top - 1].nData;
}

void MyStack::Print()
{
	if (NULL != m_pData)
	{
		cout << "The element of Stack:";
		for (int i = 0; i < m_Top; ++i)
		{
			cout << m_pData[i].nData << " ";
		}
		cout << endl;
	}
}