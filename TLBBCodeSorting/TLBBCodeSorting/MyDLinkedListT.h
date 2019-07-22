/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyDLinkedList.h
//����������˫������
//   �����ٶ���������ɾ������Ҫ�ƶ����ر��
//   ˫����붼�ܷ���
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// ˫����
template <class T>
class MyDLinkedListT
{
public:
	MyDLinkedListT();
	~MyDLinkedListT();

	bool IsEmpty();
	int  Len();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	
	DLinkListNode<T>* GetNode(int pos);
	DLinkListNode<T>* Insert(int pos, T value);
	bool Remove(int pos, T& old);
	void Clear();

private:
	DLinkListNode<T>* m_Head;
	DLinkListNode<T>* m_Rear;
};

