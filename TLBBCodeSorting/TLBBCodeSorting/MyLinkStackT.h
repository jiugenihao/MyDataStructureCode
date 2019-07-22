/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MySqStackT.h
//���������������ʵ�ֵ�ջFILO
//        �Զ����Ŵ�С��ʵʱ���䣬������ǰ���������;��������
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
	void Push(T value);		// ʼ����ͷ������
	T	 Pop();
	
	void Print();

private:
	LinkListNode<T>* m_pTop;
	int m_Size;
};

