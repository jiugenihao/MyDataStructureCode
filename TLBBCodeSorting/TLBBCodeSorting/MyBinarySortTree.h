/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�MyBinarySortTree.h
// ����������������������Ҳ�ж��������
// ������⣺�Բ���Ϊ��Ҫ������֧�ֲ����ɾ�����������������Ե�������  
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


// TODO:����ƽ����
