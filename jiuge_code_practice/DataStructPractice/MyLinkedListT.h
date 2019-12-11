/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyLinkedList.h
//功能描述：利用链表实现的线性表
//   MySinglyLinkedListT 单链表
//   查找速度慢，插入删除不需要移动，特别快
//   适合向后插入，不适合向前
//注意：
//   当pos大于现有链表长度时，返回的是尾结点
//   Insert(int pos, T value)
//   这个方法，无论单链表还是双链表，都要找到pos-1位置的结点
//栈使用：
//   Insert(0, value),Remove(0, &value)
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
	LinkListNode<T>* GetRoot() 
	{
		return this->m_pHead;
	}
	void SetRoot(LinkListNode<T>* node)
	{
		this->m_pHead = node;
	}
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
	LinkListNode<T>* Search(T value);
	LinkListNode<T>* Search(T value, MySinglyLinkedListT<T>* node);
	bool Contain(T value);
	bool Remove(T value);

	LinkListNode<T>* FindMid();			// 寻找中间结点
	LinkListNode<T>* Reverse();			// 单链表逆序,借助辅助指针后移
	LinkListNode<T>* ReverseRecur(LinkListNode<T>* head);	// 单链表逆序，递归

	friend ostream& operator << (ostream& out, const MySinglyLinkedListT<T>& list)
	{
		//out << "output all elements:" << endl;
		LinkListNode<T>* p = list.m_pHead;
		while (nullptr != p)
		{
			out << p->m_Data;
			p = p->m_pNext;
			if (nullptr != p)
				out << " ";
		}
		out << endl;
		return out;
	}

private:
	LinkListNode<T>* m_pHead;
	//int m_Len;

};


// 带头结点的单链表
template <class T>
class MyLinkedList
{
public:
	MyLinkedList()
	{
		m_pHead = new LinkListNode<T>();
		m_pHead->m_pNext = nullptr;
	}
	~MyLinkedList()
	{
		LinkListNode<T>* p = m_pHead->m_pNext;
		while (p)
		{
			LinkListNode<T>* q = p->m_pNext;
			delete q;
			q = nullptr;
		}
		delete m_pHead;
		m_pHead = nullptr;
	}

protected:
	LinkListNode<T>* m_pHead;
};

// 单循环链表
template <class T>
class MyCircleList
{
public:
	MyCircleList()
	{
		m_pHead = new LinkListNode<T>();
		m_pHead->m_pNext = m_pHead;
	}

	~MyCircleList()
	{
		LinkListNode<T>* p = m_pHead->m_pNext;
		while (p->m_pNext != m_pHead->m_pNext)
		{

		}
	}

private:
	LinkListNode<T>* m_pHead;
};
