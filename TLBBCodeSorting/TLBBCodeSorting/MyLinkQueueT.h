/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyLinkQueueT.h
//功能描述：链表表实现的队列FIFO
//        自动扩张大小，实时分配，无需提前分配或者中途扩充容量
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MyLinkQueueT
{
public:
	MyLinkQueueT();
	~MyLinkQueueT();

	bool IsEmpty();
	int  Size();
	void Clear();

	void EnQueue(T value);
	T    DeQueue();

	friend ostream& operator << (ostream& out, MyLinkQueueT<T>& queue)
	{
		out << "The elements of queue are:" << endl;
		LinkListNode<T>* p = queue.m_pHead;
		while (p)
		{
			out << p->m_Data;
			p = p->m_pNext;
			if (p) out << "-";
		}
		out << endl;
		return out;
	}
private:
	LinkListNode<T>* m_pHead;
	LinkListNode<T>* m_pTail;

};

