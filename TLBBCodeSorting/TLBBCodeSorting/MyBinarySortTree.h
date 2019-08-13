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

