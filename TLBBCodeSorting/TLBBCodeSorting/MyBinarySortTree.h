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
	BinaryNode<T>* RSearch(T value);
	BinaryNode<T>* RInsert(T value);
	bool 		   RRemove(T value);

	// non-recursion
	BinaryNode<T>* Search(T value);
	BinaryNode<T>* Insert(T value);
	bool 		   Remove(T value);

private:
	BinaryNode<T>* Search(BinaryNode<T>* pNode, T value);
	BinaryNode<T>* Insert(BinaryNode<T>* pNode, T value);
	bool 		   Remove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent);

};

