/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyIntQueue.h
//������������������ʵ�ֵ�ѭ������FIFO
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
	int m_MaxSize;		// �����д�С
	int m_Size;			// ʵ�ʶ�������
};

