/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MySqStackT.h
//����������˳���ʵ�ֵ�ջFILO
//        ��Ҫ��ǰ��������������ѷ�������ˣ���Ҫ����
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

