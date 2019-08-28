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
#include <iomanip>
#include "ConstDefine.h"

using namespace std;

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

// 二叉树的二叉链表结点
template <class T>
class BinaryNode
{
public:
	T m_Data;
	BinaryNode<T>* m_pLeft;
	BinaryNode<T>* m_pRight;

public:
	BinaryNode()
	{
		m_pLeft = nullptr;
		m_pRight = nullptr;
	}

	BinaryNode(T data, BinaryNode<T>* left = nullptr, BinaryNode<T>* right = nullptr)
	{
		m_Data   = data;
		m_pLeft  = left;
		m_pRight = right;
	}

	~BinaryNode()
	{
		m_pLeft = nullptr;
		m_pRight = nullptr;
	}
};

// 二叉树的三叉链表结点
template <class T>
class BinaryThrNode
{
private:
	T m_Data;
	BinaryThrNode<T>* m_pParent;
	BinaryThrNode<T>* m_pLeft;
	BinaryThrNode<T>* m_pRight;

public:
	BinaryThrNode()
	{
		m_pParent = nullptr;
		m_pLeft   = nullptr;
		m_pRight  = nullptr;
	}

	BinaryThrNode(T data, BinaryThrNode<T>* parent, BinaryThrNode<T>* left, BinaryThrNode<T>* right)
	{
		m_Data	  = data;
		m_pParent = parent;
		m_pLeft   = left;
		m_pRight  = right;
	}

	~BinaryThrNode()
	{
		m_pParent = nullptr;
		m_pLeft = nullptr;
		m_pRight = nullptr;
	}
};

// 线索二叉树结点
template <class T>
class ThreadBinaryNode
{
public:
	ThreadBinaryNode()
	{
		m_pLeft = nullptr;
		m_pRight = nullptr;
		lTag = rTag = 0;
	}

	ThreadBinaryNode(T data, ThreadBinaryNode<T>* left, ThreadBinaryNode<T>* right)
	{
		m_Data = data;
		m_pLeft = left;
		m_pRight = right;
		lTag = rTag = false;
	}
	~ThreadBinaryNode()
	{
		m_pLeft = nullptr;
		m_pRight = nullptr;
		lTag = rTag = false;
	}

private:
	T m_Data;
	ThreadBinaryNode<T>* m_pLeft;
	ThreadBinaryNode<T>* m_pRight;
	bool lTag, rTag;
};


// 