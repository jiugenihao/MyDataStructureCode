#include "pch.h"
#include "MyQueue.h"
#include "BaseDefine.h"

MyQueue::MyQueue(int maxSize)
{
	m_MaxSize = maxSize;
	m_pData = new QueueItem[m_MaxSize];
	m_Head = 0;
	m_Tail = 0;
	m_Size = 0;
}

MyQueue::~MyQueue()
{
	SAFE_DELETE_ARRAY(m_pData);
}

bool MyQueue::IsFull()
{
	if(m_pData[m_Tail].bUsed == true)
	{
		return true;
	}
	return false;
}

bool MyQueue::IsEmpty()
{
	if (m_pData[m_Head].bUsed == false)
	{
		return true;
	}
	return false;
}

bool MyQueue::PushBack(int value)
{
	if (IsFull()) return false;
	m_pData[m_Tail].nData = value;
	m_pData[m_Tail].bUsed = true;
	m_Tail++;
	m_Size++;
	if (m_Tail >= MAX_QUEUE_SIZE) m_Tail = 0;

	return true;
}

int MyQueue::PopFront()
{
	if (m_pData[m_Head].bUsed == false) return false;

	int tmp = m_pData[m_Head].nData;
	m_pData[m_Head].nData = 0;
	m_pData[m_Head].bUsed = false;
	m_Head++;
	m_Size--;
	if (m_Head >= MAX_QUEUE_SIZE) m_Head = 0;

	return tmp;
}

// m_Head==m_Tail�����������0��Ԫ�غͶ�����
//int MyQueue::GetSize()
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
int MyQueue::GetSize()
{
	return m_Size;
}