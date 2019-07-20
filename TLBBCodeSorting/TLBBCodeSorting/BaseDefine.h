/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�BaseDefine.h
//����������ϵͳ�ײ����ͻ����ļ�������Ȩ��Ա�����޸Ĵ��ļ�����
//�汾˵����Windows����ϵͳ��Ҫ����꣺__WINDOWS__
//			Linux����ϵͳ��Ҫ����꣺__LINUX__
//�޸������
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>

using namespace std;


#ifndef SAFE_DELETE
#define SAFE_DELETE(x) if(nullptr!=(x)){delete (x); (x)=nullptr;}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) if(nullptr!=(x)){delete[] (x); (x)=nullptr;}
#endif

// ������ڵ��࣬����ͷ���
template <class T>
class LinkListNode
{
public:
	T m_Data;
	LinkListNode<T>* m_pNext;

public:
	LinkListNode()
	{
		m_pNext = nullptr;
	}
	LinkListNode(T data, LinkListNode<T>* next = nullptr)
	{
		m_Data = data;
		m_pNext = next;
	}
	~LinkListNode()
	{
		m_pNext = nullptr;
	}
};
