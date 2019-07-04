/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyQueue.h
//功能描述：利用数组实现的循环队列
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_QUEUE_SIZE 5

struct QueueItem
{
	int  nData;
	bool bUsed;
};
class MyQueue
{
public:
	MyQueue(int maxSize = MAX_QUEUE_SIZE);
	~MyQueue();

	bool PushBack(int value);
	int  PopFront();
	int  GetSize();
	bool IsFull();
	bool IsEmpty();
	void Print();

private:
	QueueItem* m_pData;
	int m_Head;
	int m_Tail;
	int m_MaxSize;		// 最大队列大小
	int m_Size;			// 实际队列容量
};

