/////////////////////////////////////////////////////////////////////////////////
// 文件名称：MyBinarySortTree.h
// 功能描述：二叉排序树，也叫二叉查找树
// 解决问题：以查找为主要操作，支持插入和删除操作，具有排序性的数据列  
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "MyBinaryTreeT.h"

template <class T>
class MyBinarySortTree : public MyBinaryTreeT<T>
{
public:
	MyBinarySortTree();
	~MyBinarySortTree();

public:
	// recursion
	BinaryNode<T>* RecursiveSearch(T value);
	BinaryNode<T>* RecursiveInsert(T value);
	bool 		   RecursiveRemove(T value);

	// non-recursion
	BinaryNode<T>* Search(T value);
	BinaryNode<T>* Insert(T value);
	bool 		   Remove(T value);

private:
	BinaryNode<T>* RecursiveSearch(BinaryNode<T>* pNode, T value);
	BinaryNode<T>* RecursiveInsert(BinaryNode<T>* pNode, T value);
	bool 		   RecursiveRemove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent);

};


// TODO:二叉平衡树
