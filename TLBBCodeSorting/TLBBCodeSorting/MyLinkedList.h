/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyLinkedList.h
//功能描述：利用链表实现的顺序表
//   MySinglyLinkedList 单链表
//   查找速度慢，插入删除不需要移动，特别快
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// 单链表-不带头结点
template <class T>
class MySinglyLinkedList
{
public:
	MySinglyLinkedList();
	MySinglyLinkedList(T value[], int n);
	~MySinglyLinkedList();

public:
	bool IsEmpty();
	int	 Len();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	LinkListNode<T>* GetNode(int pos);	// 无法用于头结点的某些操作
	LinkListNode<T>* Insert(int pos, T value);	// pos位置插入新节点
	bool Remove(int pos, T& old);
	void Clear();
	void Concat(MySinglyLinkedList<T>& list);
	void Visit();

	friend ostream& operator << (ostream& out, MySinglyLinkedList<T>& list)
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

