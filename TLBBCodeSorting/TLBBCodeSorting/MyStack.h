/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyStack.h
//功能描述：利用数组实现的栈FILO
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#define MAX_STACK_SIZE 5

struct StackItem
{
	int nData;
	//bool bUsed;
};

class MyStack
{
public:
	MyStack(int max_size = MAX_STACK_SIZE);
	~MyStack();

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
