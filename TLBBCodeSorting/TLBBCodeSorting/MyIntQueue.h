/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyIntQueue.h
//功能描述：利用数组实现的循环队列FIFO
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

struct QueueItem
{
	int  nData;
	bool bUsed;
};
class MyIntQueue
{
public:
	MyIntQueue(int maxSize = MAX_QUEUE_SIZE);
	~MyIntQueue();

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

