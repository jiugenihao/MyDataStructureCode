/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyLinkedList.h
//功能描述：利用链表实现的线性表
//   MySinglyLinkedListT 单链表
//   查找速度慢，插入删除不需要移动，特别快
//   适合向后插入，不适合向前
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// 单链表-不带头结点
template <class T>
class MySinglyLinkedListT
{
public:
	MySinglyLinkedListT();
	MySinglyLinkedListT(T value[], int n);
	~MySinglyLinkedListT();

public:
	bool IsEmpty();
	int	 Size();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	LinkListNode<T>* GetNode(int pos);	// 无法用于头结点的某些操作
	LinkListNode<T>* Insert(int pos, T value);	// pos位置插入新节点
	bool Remove(int pos, T& old);
	void Clear();
	void Concat(MySinglyLinkedListT<T>& list);
	void Visit();

	friend ostream& operator << (ostream& out, MySinglyLinkedListT<T>& list)
	{
		out << "output all elements:" << endl;
		LinkListNode<T>* p = list.m_Head;
		while (nullptr != p)
		{
			out << p->m_Data;
			p = p->m_pNext;
			if (nullptr != p)
				out << "-";
		}
		out << endl;
		return out;
	}

private:
	LinkListNode<T>* m_Head;
	//int m_Len;

};


// 带头结点的单链表

