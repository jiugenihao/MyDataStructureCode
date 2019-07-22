/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyDLinkedList.h
//功能描述：双向链表
//   查找速度慢，插入删除不需要移动，特别快
//   双向插入都很方便
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// 双链表
template <class T>
class MyDLinkedListT
{
public:
	MyDLinkedListT();
	~MyDLinkedListT();

	bool IsEmpty();
	int  Len();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	
	DLinkListNode<T>* GetNode(int pos);
	DLinkListNode<T>* Insert(int pos, T value);
	bool Remove(int pos, T& old);
	void Clear();

private:
	DLinkListNode<T>* m_Head;
	DLinkListNode<T>* m_Rear;
};

