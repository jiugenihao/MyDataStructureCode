/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyDLinkedList.h
//功能描述：双向链表
//   查找速度慢，插入删除不需要移动，特别快
//   双向插入都很方便
//注意：
//   当pos大于现有链表长度时，返回的是尾结点
//   Insert(int pos, T value)
//   这个方法，无论单链表还是双链表，都要找到pos-1位置的结点
//栈使用：
//   Insert(0, value),Remove(0, &value)
//
//单双链表的不同之处：插入和删除操作，因为涉及双向指针的修改
//其他操作基本一样，都只涉及单向指针完成，比如Size，Get，Find
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// 双链表-不带头结点
template <class T>
class MyDLinkedListT
{
public:
	MyDLinkedListT();
	MyDLinkedListT(T value[], int n);
	~MyDLinkedListT();

	// immutable
	bool IsEmpty();
	int  Size();

	// mutable
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	DLinkListNode<T>* GetNode(int pos);
	DLinkListNode<T>* Insert(int pos, T value);
	bool Remove(int pos, T& old);
	void Clear();
	void Concat(MyDLinkedListT<T>& list);
	
	friend ostream& operator << (ostream& out, const MyDLinkedListT<T>& list)
	{
		//out << "dlinklist's size is:" << Size() << endl;
		out << "output all elements:" << endl;
		DLinkListNode<T>* p = list.m_pHead;
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
	DLinkListNode<T>* m_pHead;
	//DLinkListNode<T>* m_Rear;
	int m_Size;
};

