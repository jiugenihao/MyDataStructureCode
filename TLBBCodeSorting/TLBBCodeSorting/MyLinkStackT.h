/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MySqStackT.h
//���������������ʵ�ֵ�ջFILO
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
	void Push(T value);		// ʼ����ͷ������
	T	 Pop();
	T    GetTop();
	int  Size();

private:
	LinkListNode<T>* m_pTop;
	int m_Size;
};

