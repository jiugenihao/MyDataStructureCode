/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�MyBinaryTreeT.h
//������������������ʵ�ֵĶ�����
//   
//���������������Ϊ����^��ʾ
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MyBinaryTreeT
{
public:
	MyBinaryTreeT();								// ����ն�����
	MyBinaryTreeT(T preList[], int n);				// ���������й���һ�ö�����
	MyBinaryTreeT(T preList[], T inList[], int n);	// ��������������й���һ�ö�����
	virtual ~MyBinaryTreeT();

	bool IsEmpty();
	BinaryNode<T>* GetRoot();
	void SetRoot(BinaryNode<T>* node);
	
public:
	// recursion traversal
	void PreOrder();
	void InOrder();
	void PostOrder();
	int  Count();
	int  Height();

private:
	// �ݹ���������ǣ�nullptr == node
	void PreOrder(BinaryNode<T>* node);		// ǰ���������
	void InOrder(BinaryNode<T>* node);		// �����������
	void PostOrder(BinaryNode<T>* node);	// ������������
	int  Count(BinaryNode<T>* node);		// ��������������
	int  Height(BinaryNode<T>* node);		// ���������߶�

public:
	BinaryNode<T>* Search(T value);			// �����״γ��ֵ�ֵΪvalue�Ľ��
	BinaryNode<T>* GetParent(BinaryNode<T>* node);
	void		   GetAllAncestorNode(T value);	// ��ȡvalue�Ľ������Ƚ��
	void           PrintGList();			// �Թ�������������

private:
	BinaryNode<T>* Search(BinaryNode<T>* node, T value);
	BinaryNode<T>* GetParent(BinaryNode<T>* p, BinaryNode<T>* node);
	void		   PrintGList(BinaryNode<T>* node);

public:
	BinaryNode<T>* Insert(BinaryNode<T>* node, T value, bool left = true);		// ����һ�����
	void RemoveChild(BinaryNode<T>* node, bool left = true);					// ɾ��һ������
	//void Remove();

	// non-recursive traversal
	void PreOrderTraverse();
	void InOrderTraverse();
	void PostOrderTraverse();
	void LevelOrder();

private:
	BinaryNode<T>* Create(T preList[], int n, int& i);	// �Ա���������������������д�������
	BinaryNode<T>* Create(T preList[], T inList[], int preStart, int inStart, int n);	// ��������������д�������
	void Destroy(BinaryNode<T>* node);		// �ú���������ٶ�����

protected:
	BinaryNode<T>* m_pRoot;
};


// ��ȫ������
template <class T>
class CompleteBinaryTree : public MyBinaryTreeT<T>
{
public:
	CompleteBinaryTree() {}
	CompleteBinaryTree(T levelList[], int n);

private:
	BinaryNode<T>* Create(T levelList[], int n, int i);

};