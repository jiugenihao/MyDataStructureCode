/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyLinkedList.h
//������������������ʵ�ֵ����Ա�
//   MySinglyLinkedListT ������
//   �����ٶ���������ɾ������Ҫ�ƶ����ر��
//   �ʺ������룬���ʺ���ǰ
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

// ������-����ͷ���
template <class T>
class MySinglyLinkedListT
{
public:
	MySinglyLinkedListT();
	MySinglyLinkedListT(T value[], int n);
	~MySinglyLinkedListT();

public:
	bool IsEmpty();
	int	 Size();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	LinkListNode<T>* GetNode(int pos);	// �޷�����ͷ����ĳЩ����
	LinkListNode<T>* Insert(int pos, T value);	// posλ�ò����½ڵ�
	bool Remove(int pos, T& old);
	void Clear();
	void Concat(MySinglyLinkedListT<T>& list);
	void Visit();

	friend ostream& operator << (ostream& out, MySinglyLinkedListT<T>& list)
	{
		out << "output all elements:" << endl;
		LinkListNode<T>* p = list.m_Head;
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
	LinkListNode<T>* m_Head;
	//int m_Len;

};


// ��ͷ���ĵ�����

