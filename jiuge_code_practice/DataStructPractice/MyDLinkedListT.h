/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyDLinkedList.h
//����������˫������
//   �����ٶ���������ɾ������Ҫ�ƶ����ر��
//   ˫����붼�ܷ���
//ע�⣺
//   ��pos��������������ʱ�����ص���β���
//   Insert(int pos, T value)
//   ������������۵�������˫������Ҫ�ҵ�pos-1λ�õĽ��
//ջʹ�ã�
//   Insert(0, value),Remove(0, &value)
//
//��˫����Ĳ�֮ͬ���������ɾ����������Ϊ�漰˫��ָ����޸�
//������������һ������ֻ�漰����ָ����ɣ�����Size��Get��Find
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// ˫����-����ͷ���
template <class T>
class MyDLinkedListT
{
public:
	MyDLinkedListT();
	MyDLinkedListT(T value[], int n);
	~MyDLinkedListT();

	// immutable
	bool IsEmpty();
	int  Size();

	// mutable
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	DLinkListNode<T>* GetNode(int pos);
	DLinkListNode<T>* Insert(int pos, T value);
	bool Remove(int pos, T& old);
	void Clear();
	void Concat(MyDLinkedListT<T>& list);
	
	friend ostream& operator << (ostream& out, const MyDLinkedListT<T>& list)
	{
		//out << "dlinklist's size is:" << Size() << endl;
		out << "output all elements:" << endl;
		DLinkListNode<T>* p = list.m_pHead;
		while (nullptr != p)
		{
			out << p->m_Data;
			p = p->m_pNext;
			if (nullptr != p)
				out << "-";
		}
		out << endl;
		return out;
	}

private:
	DLinkListNode<T>* m_pHead;
	//DLinkListNode<T>* m_Rear;
	int m_Size;
};

