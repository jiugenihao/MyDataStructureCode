#include "pch.h"
#include "MyIntStack.h"
#include "BaseDefine.h"

MyIntStack::MyIntStack(int maxSize):m_MaxSize(maxSize)
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


MyIntStack::~MyIntStack()
{
	SAFE_DELETE_ARRAY(m_pData);
}

bool MyIntStack::IsFull()
{
	return m_Top >= m_MaxSize;
}
bool MyIntStack::IsEmpty()
{
	return (m_Top == 0);
}
bool MyIntStack::Push(int value)
{
	if (IsFull())
	{
		return false;
	}
	
	m_pData[m_Top].nData = value;
	m_Top++;

	return true;
}

int MyIntStack::Pop()
{
	if (IsEmpty())
	{
		return 0;
	}
	
	int tmp = m_pData[m_Top-1].nData;
	m_Top--;

	return tmp;
}

int MyIntStack::GetTop()
{
	if (IsEmpty())
	{
		return 0;
	}
	return m_pData[m_Top - 1].nData;
}

void MyIntStack::Print()
{
	if (nullptr != m_pData)
	{
		cout << "The element of Stack:";
		for (int i = 0; i < m_Top; ++i)
		{
			cout << m_pData[i].nData << " ";
		}
		cout << endl;
	}
}