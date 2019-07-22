#include "pch.h"
#include "MyIntQueue.h"
#include "BaseDefine.h"

MyIntQueue::MyIntQueue(int maxSize):m_MaxSize(maxSize)
{
	//m_MaxSize = maxSize;
	m_pData = new QueueItem[m_MaxSize];
	for (int i = 0; i < m_MaxSize; ++i)
	{
		m_pData[i].nData = 0;
		m_pData[i].bUsed = false;
	}
	m_Head = 0;
	m_Tail = 0;
	m_Size = 0;
}

MyIntQueue::~MyIntQueue()
{
	SAFE_DELETE_ARRAY(m_pData);
}

bool MyIntQueue::IsFull()
{
	// if (m_Size >= m_MaxSize) return true;
	if(m_pData[m_Tail].bUsed == true)
	{
		return true;
	}
	return false;
}

bool MyIntQueue::IsEmpty()
{
	// if (m_Size == 0) return true;
	if (m_pData[m_Head].bUsed == false)
	{
		return true;
	}
	return false;
}

bool MyIntQueue::PushBack(int value)
{
	if (IsFull()) return false;
	m_pData[m_Tail].nData = value;
	m_pData[m_Tail].bUsed = true;
	m_Tail++;
	m_Size++;
	if (m_Tail >= m_MaxSize) m_Tail = 0;

	return true;
}

int MyIntQueue::PopFront()
{
	if (m_pData[m_Head].bUsed == false) return false;

	int tmp = m_pData[m_Head].nData;
	m_pData[m_Head].nData = 0;
	m_pData[m_Head].bUsed = false;
	m_Head++;
	m_Size--;
	if (m_Head >= m_MaxSize) m_Head = 0;

	return tmp;
}

// m_Head==m_Tail有两种情况：0个元素和队列满
//int MyIntQueue::GetSize()
//{
//	if (IsFull()) return MAX_QUEUE_SIZE;
//	if (m_Head < m_Tail)
//	{
//		return m_Tail - m_Head;
//	}
//	else if (m_Tail < m_Head)
//	{
//		return MAX_QUEUE_SIZE - (m_Head - m_Tail);
//	}
//	else
//	{
//		return 0;
//	}
//}
int MyIntQueue::GetSize()
{
	return m_Size;
}

void MyIntQueue::Print()
{
	if (nullptr != m_pData)
	{
		cout << "The element of queue are ";
		for (int i = 0; i < m_MaxSize; ++i)
		{
			cout << m_pData[i].nData << " ";
		}
		cout << "\n";
	}
	cout << "my queue : head[" << m_Head << "] tail[" << m_Tail << "]" << endl;
}