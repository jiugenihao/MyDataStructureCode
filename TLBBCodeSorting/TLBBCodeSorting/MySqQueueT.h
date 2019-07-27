///////////////////////////////////////////////////////////////
//�ļ����ƣ�MySqQueueT.h
//����������˳���ʵ�ֵĶ���FIFO
//        ��Ҫ��ǰ��������������ѷ�������ˣ���Ҫ����
//
//˳�����ΪʲôҪ��ѭ������?
//   1.˳����л���ɼ���������ǳ��Ӻ�front�±�һֱ���ƣ�frontǰ���Ԫ��
//   ���ǿյģ������޷������ˣ��˷ѿռ�
//   2.һ�����\���Ӳ�����Ҫͬʱ�ı������±�
//
//ѭ�������п�������m_Head == m_Tail
//ѭ����������������m_Head == (m_Tail+1) % m_Size
//����:m_Head = (m_Head + 1) % m_Size
//���:m_Tail = (m_Tail + 1) % m_Size
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
	int m_Head;		// ��ͷ
	int m_Tail;		// ��β
	int m_Size;
};

