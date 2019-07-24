/////////////////////////////////////////////////////////////////////////////////
//文件名称：BaseDefine.h
//功能描述：系统底层类型基础文件，无授权人员不得修改此文件内容
//版本说明：Windows操作系统需要定义宏：__WINDOWS__
//			Linux操作系统需要定义宏：__LINUX__
//修改情况：
//
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>

using namespace std;

// consts and defines
#define MAX_LIST_SIZE  4
#define MAX_STACK_SIZE 4
#define MAX_QUEUE_SIZE 4

#ifndef SAFE_DELETE
#define SAFE_DELETE(x) if(nullptr!=(x)){delete (x); (x)=nullptr;}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) if(nullptr!=(x)){delete[] (x); (x)=nullptr;}
#endif

// 单链表节点类，不带头结点
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

// 双链表节点类
template <typename T>
class DLinkListNode
{
public:
	T m_Data;
	DLinkListNode<T>* m_pPrev;
	DLinkListNode<T>* m_pNext;

public:
	DLinkListNode()
	{
		m_pPrev = nullptr;
		m_pNext = nullptr;
	}

	DLinkListNode(T data, DLinkListNode<T>* prev = nullptr, DLinkListNode<T>* next = nullptr)
	{
		m_Data  = data;
		m_pPrev = prev;
		m_pNext = next;
	}

	~DLinkListNode()
	{
		m_pPrev = nullptr;
		m_pNext = nullptr;
	}
};