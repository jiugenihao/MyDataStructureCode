/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyLinkedList.h
//功能描述：利用链表实现的顺序表
//   MySinglyLinkedList 单链表
//   查找速度慢，插入删除不需要移动，特别快
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class LinkListNode
{
public:
	T m_Data;
	LinkListNode<T>* m_pNext;

public:
	LinkListNode()
	{
		m_pNext = nullptr;
	}
	LinkListNode(T data, LinkListNode<T>* next = nullptr)
	{
		m_Data = data;
		m_pNext = next;
	}
	~LinkListNode()
	{
		m_pNext = nullptr;
	}
};

// 单链表
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
	LinkListNode<T>* GetNode(int pos);
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
	int m_Len;

};

