/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyIntStack.h
//功能描述：利用数组实现的栈FILO
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

struct StackItem
{
	int nData;
	//bool bUsed;
};

class MyIntStack
{
public:
	MyIntStack(int max_size = MAX_STACK_SIZE);
	~MyIntStack();

	bool IsFull();
	bool IsEmpty();
	bool Push(int value);
	int Pop();
	int GetTop();
	void Print();

private:
	StackItem* m_pData;
	int m_Top;			// 栈顶值
	int m_MaxSize;
	//int m_Size;
};
