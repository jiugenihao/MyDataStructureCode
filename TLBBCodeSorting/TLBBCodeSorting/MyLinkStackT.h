/////////////////////////////////////////////////////////////////////////////////
//文件名称：MySqStackT.h
//功能描述：链表表实现的栈FILO
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MyLinkStackT
{
public:
	MyLinkStackT();
	~MyLinkStackT();

	bool IsEmpty();
	void Clear();
	void Push(T value);		// 始终是头部插入
	T	 Pop();
	T    GetTop();
	int  Size();

private:
	LinkListNode<T>* m_pTop;
	int m_Size;
};

