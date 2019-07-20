/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MySqStackT.h
//����������˳���ʵ�ֵ�ջFILO
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

