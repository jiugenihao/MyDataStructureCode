/////////////////////////////////////////////////////////////////////////////////
//文件名称：MySqStackT.h
//功能描述：链表表实现的栈FILO
//        自动扩张大小，实时分配，无需提前分配或者中途扩充容量
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MyLinkStackT
{
public:
	MyLinkStackT();
	~MyLinkStackT();

	void Clear();
	bool IsEmpty();
	int  Size();
	T    GetTop();
	void Push(T value);		// 始终是头部插入
	T	 Pop();
	
	void Print();

private:
	LinkListNode<T>* m_pTop;
	int m_Size;
};

