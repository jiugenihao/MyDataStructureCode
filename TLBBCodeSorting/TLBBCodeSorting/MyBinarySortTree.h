/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyBinarySortTree.h
//功能描述：二叉排序树
//   
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
	BinaryNode<T>* Search(T value);
	BinaryNode<T>* Insert(T value);
	bool 		   Remove(T value);

private:
	BinaryNode<T>* Insert(BinaryNode<T>* pNode, T value);
	bool 		   Remove(T value, BinaryNode<T>* pNode, BinaryNode<T>* pParent);

};

