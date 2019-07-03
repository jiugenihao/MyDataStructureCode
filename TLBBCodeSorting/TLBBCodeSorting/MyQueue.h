/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyQueue.h
//������������������ʵ�ֵ�ѭ������
//
/////////////////////////////////////////////////////////////////////////////////

#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__

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
	MyQueue();
	~MyQueue();

	bool PushBack(int value);
	int  PopFront();
	int  GetSize();
	bool IsFull();
	bool IsEmpty();

private:
	QueueItem* m_pData;
	int m_Head;
	int m_Tail;
	int m_Size;
};

extern MyQueue g_MyQueue;

#endif
