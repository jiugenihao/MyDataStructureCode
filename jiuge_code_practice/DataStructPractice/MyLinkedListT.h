/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyLinkedList.h
//������������������ʵ�ֵ����Ա�
//   MySinglyLinkedListT ������
//   �����ٶ���������ɾ������Ҫ�ƶ����ر��
//   �ʺ������룬���ʺ���ǰ
//ע�⣺
//   ��pos��������������ʱ�����ص���β���
//   Insert(int pos, T value)
//   ������������۵�������˫������Ҫ�ҵ�pos-1λ�õĽ��
//ջʹ�ã�
//   Insert(0, value),Remove(0, &value)
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
	LinkListNode<T>* GetRoot() 
	{
		return this->m_pHead;
	}
	void SetRoot(LinkListNode<T>* node)
	{
		this->m_pHead = node;
	}
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
	LinkListNode<T>* Search(T value);
	LinkListNode<T>* Search(T value, MySinglyLinkedListT<T>* node);
	bool Contain(T value);
	bool Remove(T value);

	LinkListNode<T>* FindMid();			// Ѱ���м���
	LinkListNode<T>* Reverse();			// ����������,��������ָ�����
	LinkListNode<T>* ReverseRecur(LinkListNode<T>* head);	// ���������򣬵ݹ�

	friend ostream& operator << (ostream& out, const MySinglyLinkedListT<T>& list)
	{
		//out << "output all elements:" << endl;
		LinkListNode<T>* p = list.m_pHead;
		while (nullptr != p)
		{
			out << p->m_Data;
			p = p->m_pNext;
			if (nullptr != p)
				out << " ";
		}
		out << endl;
		return out;
	}

private:
	LinkListNode<T>* m_pHead;
	//int m_Len;

};


// ��ͷ���ĵ�����
template <class T>
class MyLinkedList
{
public:
	MyLinkedList()
	{
		m_pHead = new LinkListNode<T>();
		m_pHead->m_pNext = nullptr;
	}
	~MyLinkedList()
	{
		LinkListNode<T>* p = m_pHead->m_pNext;
		while (p)
		{
			LinkListNode<T>* q = p->m_pNext;
			delete q;
			q = nullptr;
		}
		delete m_pHead;
		m_pHead = nullptr;
	}

protected:
	LinkListNode<T>* m_pHead;
};

// ��ѭ������
template <class T>
class MyCircleList
{
public:
	MyCircleList()
	{
		m_pHead = new LinkListNode<T>();
		m_pHead->m_pNext = m_pHead;
	}

	~MyCircleList()
	{
		LinkListNode<T>* p = m_pHead->m_pNext;
		while (p->m_pNext != m_pHead->m_pNext)
		{

		}
	}

private:
	LinkListNode<T>* m_pHead;
};
