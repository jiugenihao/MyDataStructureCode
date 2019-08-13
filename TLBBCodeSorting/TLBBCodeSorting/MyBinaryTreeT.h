/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyBinaryTreeT.h
//功能描述：二叉链表实现的二叉树
//   
//标明空子树：结点为空用^表示
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

template <class T>
class MyBinaryTreeT
{
public:
	MyBinaryTreeT();								// 构造空二叉树
	MyBinaryTreeT(T preList[], int n);				// 以先序序列构造一棵二叉树
	MyBinaryTreeT(T preList[], T inList[], int n);	// 以先序和中序序列构造一棵二叉树
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
	// 递归结束条件是：nullptr == node
	void PreOrder(BinaryNode<T>* node);		// 前序遍历子树
	void InOrder(BinaryNode<T>* node);		// 中序遍历子树
	void PostOrder(BinaryNode<T>* node);	// 后续遍历子树
	int  Count(BinaryNode<T>* node);		// 返回子树结点个数
	int  Height(BinaryNode<T>* node);		// 返回子树高度

public:
	BinaryNode<T>* Search(T value);			// 查找首次出现的值为value的结点
	BinaryNode<T>* GetParent(BinaryNode<T>* node);
	void		   GetAllAncestorNode(T value);	// 获取value的结点的祖先结点
	void           PrintGList();			// 以广义表输出二叉树

private:
	BinaryNode<T>* Search(BinaryNode<T>* node, T value);
	BinaryNode<T>* GetParent(BinaryNode<T>* p, BinaryNode<T>* node);
	void		   PrintGList(BinaryNode<T>* node);

public:
	BinaryNode<T>* Insert(BinaryNode<T>* node, T value, bool left = true);		// 插入一个结点
	void RemoveChild(BinaryNode<T>* node, bool left = true);					// 删除一棵子树
	//void Remove();

	// non-recursive traversal
	void PreOrderTraverse();
	void InOrderTraverse();
	void PostOrderTraverse();
	void LevelOrder();

private:
	BinaryNode<T>* Create(T preList[], int n, int& i);	// 以标明空子树的先序遍历序列创建子树
	BinaryNode<T>* Create(T preList[], T inList[], int preStart, int inStart, int n);	// 以先序和中序序列创建子树
	void Destroy(BinaryNode<T>* node);		// 用后序遍历销毁二叉树

protected:
	BinaryNode<T>* m_pRoot;
};


// 完全二叉树
template <class T>
class CompleteBinaryTree : public MyBinaryTreeT<T>
{
public:
	CompleteBinaryTree() {}
	CompleteBinaryTree(T levelList[], int n);

private:
	BinaryNode<T>* Create(T levelList[], int n, int i);

};