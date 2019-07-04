/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyQueue.h
//������������������ʵ�ֵ�ѭ������
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#define MAX_STACK_SIZE 5

struct StackItem
{
	int nData;
	bool bUsed;
};

class MyStack
{
public:
	MyStack();
	~MyStack();

	bool Push(int value);
	int Pop();
	bool IsFull();
	bool IsEmpty();

private:
	StackItem* m_pData;
	int m_Top;
	int m_MaxSize;
	int m_Size;
};
