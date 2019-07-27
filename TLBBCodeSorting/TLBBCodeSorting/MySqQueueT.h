///////////////////////////////////////////////////////////////
//文件名称：MySqQueueT.h
//功能描述：顺序表实现的队列FIFO
//        需要提前分配容量，如果已分配的满了，需要扩容
//
//顺序队列为什么要用循环队列?
//   1.顺序队列会造成假溢出，就是出队后front下标一直后移，front前面的元素
//   都是空的，但是无法利用了，浪费空间
//   2.一次入队\出队操作需要同时改变两个下标
//
//循环队列判空条件：m_Head == m_Tail
//循环队列判满条件：m_Head == (m_Tail+1) % m_Size
//出队:m_Head = (m_Head + 1) % m_Size
//入队:m_Tail = (m_Tail + 1) % m_Size
///////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MySqQueueT
{
public:
	MySqQueueT(int size = MAX_QUEUE_SIZE);
	~MySqQueueT();

	// immutable
	bool IsEmpty();
	bool IsFull();
	int  Size();
	T    GetHead();
	T    GetTail();

	// mutable
	void EnQueue(T value);
	T    DeQueue();

	friend ostream& operator << (ostream& out, MySqQueueT& queue)
	{
		out << "The elements of queue are:" << endl;
		out << "head = " << queue.m_Head << " tail = " << queue.m_Tail << endl;
		out << queue.m_pData[queue.m_Head];
		if (queue.m_Head <= queue.m_Tail)
		{
			for (int i = queue.m_Head + 1; i < queue.m_Tail; ++i)
			{
				out << "-" << queue.m_pData[i];
			}
		}
		else
		{
			for (int i = queue.m_Head + 1; i < queue.m_Size; ++i)
			{
				out << "-" << queue.m_pData[i];
			}
			for (int i = 0; i < queue.m_Tail; ++i)
			{
				out << "-" << queue.m_pData[i];
			}
		}
		
		out << endl;
		return out;
	}

private:
	T*  m_pData;
	int m_Head;		// 队头
	int m_Tail;		// 队尾
	int m_Size;
};

