/////////////////////////////////////////////////////////////////////////////////
//文件名称：MySqStackT.h
//功能描述：顺序表实现的栈FILO
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MySqStackT
{
public:
	MySqStackT(int size = 64);
	~MySqStackT();

	bool IsEmpty();
	bool IsFull();
	void Push(T value);
	T	 Pop();
	T	 GetTop();

private:
	T*  m_pElem;
	int m_Top;
	int m_Size;
};

