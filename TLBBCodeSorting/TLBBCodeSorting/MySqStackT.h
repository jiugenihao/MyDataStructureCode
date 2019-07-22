/////////////////////////////////////////////////////////////////////////////////
//文件名称：MySqStackT.h
//功能描述：顺序表实现的栈FILO
//        需要提前分配容量，如果已分配的满了，需要扩容
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MySqStackT
{
public:
	MySqStackT(int size = 64);
	~MySqStackT();

	// immutable function
	bool IsEmpty();
	bool IsFull();
	int  Size();
	T	 GetTop();

	// mutable function
	void Clear();
	void Push(T value);
	T	 Pop();
	
	// traverse
	void Print();

private:
	T*  m_pElem;
	int m_Top;
	int m_Size;
};

