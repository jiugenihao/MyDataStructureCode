#include "pch.h"
#include "MyBinaryTreeT.h"
#include "MyLinkStackT.h"
#include "MyLinkQueueT.h"

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT()
{
	m_pRoot = nullptr;
}

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT(T preList[], int n)
{
	int i = 0;
	m_pRoot = Create(preList, n, i);
}

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT(T preList[], T inList[], int n)
{
	m_pRoot = Create(preList, inList, 0, 0, n);
}

template <class T>
MyBinaryTreeT<T>::~MyBinaryTreeT()
{
	Destroy(m_pRoot);
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::GetRoot()
{
	return m_pRoot;
}

template <class T>
void MyBinaryTreeT<T>::SetRoot(BinaryNode<T>* node)
{
	m_pRoot = node;
}

// 后序遍历来删除，先删左右结点再删自身
template <class T>
void MyBinaryTreeT<T>::Destroy(BinaryNode<T>* node)
{
	if (node)
	{
		Destroy(node->m_pLeft);
		Destroy(node->m_pRight);
		delete node;
	}
}

template <class T>
bool MyBinaryTreeT<T>::IsEmpty()
{
	return (m_pRoot == nullptr);
}

template <class T>
void MyBinaryTreeT<T>::PreOrder()
{
	cout << "先序遍历二叉树：";
	PreOrder(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PreOrder(BinaryNode<T>* node)
{
	if (node)
	{
		cout << node->m_Data;
		PreOrder(node->m_pLeft);
		PreOrder(node->m_pRight);
	}
}

template <class T>
void MyBinaryTreeT<T>::InOrder()
{
	cout << "中序遍历二叉树：";
	InOrder(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::InOrder(BinaryNode<T>* node)
{
	if (node)
	{
		InOrder(node->m_pLeft);
		cout << node->m_Data;
		InOrder(node->m_pRight);
	}
}

template <class T>
void MyBinaryTreeT<T>::PostOrder()
{
	cout << "后序遍历二叉树：";
	PostOrder(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PostOrder(BinaryNode<T>* node)
{
	if (node)
	{
		PostOrder(node->m_pLeft);
		PostOrder(node->m_pRight);
		cout << node->m_Data;
	}
}

template <class T>
int MyBinaryTreeT<T>::Count()
{
	return Count(m_pRoot);
}

template <class T>
int MyBinaryTreeT<T>::Count(BinaryNode<T>* node)
{
	if (node)
	{
		return 1 + Count(node->m_pLeft) + Count(node->m_pRight);
	}
	return 0;
}

template <class T>
int MyBinaryTreeT<T>::Height()
{
	return Height(m_pRoot);
}

// 采用后序层次遍历
template <class T>
int MyBinaryTreeT<T>::Height(BinaryNode<T>* node)
{
	if (node)
	{
		int lh = Height(node->m_pLeft);
		int rh = Height(node->m_pRight);
		
		return (lh >= rh) ? lh+1 : rh+1;
	}
	return 0;
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Search(T value)
{
	return Search(m_pRoot, value);
}

// 采用先序遍历查找
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Search(BinaryNode<T>* node, T value)
{
	BinaryNode<T>* pFind = nullptr;

	if (!node)
		return nullptr;
	
	if (node->m_Data == value)
	{
		return node;
	}
	pFind = Search(node->m_pLeft, value);
	if (!pFind)
	{
		pFind = Search(node->m_pRight, value);
	}

	return pFind;
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::GetParent(BinaryNode<T>* node)
{
	if (!m_pRoot || !node || node == m_pRoot)
	{
		return nullptr;
	}
	return GetParent(m_pRoot, node);
}

// 采用先序遍历获取
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::GetParent(BinaryNode<T>* parent, BinaryNode<T>* node)
{
	BinaryNode<T>* pFind = nullptr;

	if (parent)
	{
		if (parent->m_pLeft == node || parent->m_pRight == node)
			return parent;
		pFind = GetParent(parent->m_pLeft, node);
		if (!pFind)
		{
			pFind = GetParent(parent->m_pRight, node);
		}
	}

	return pFind;
}

template <class T>
void MyBinaryTreeT<T>::GetAllAncestorNode(T value)
{
	BinaryNode<T>* find = Search(value);
	if (find)
	{
		cout << value << "的祖先结点是：";
		BinaryNode<T>* parent = GetParent(find);
		while (parent)
		{
			cout << parent->m_Data << " ";
			parent = GetParent(parent);
		}
		cout << endl;
	}
	else
		cout << "没有找到该结点" << endl;
}

// 用标明空子树的先序序列创建二叉树，构造所有子树的根结点
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Create(T preList[], int n, int& i)
{
	BinaryNode<T>* p = nullptr;

	if (i < n)
	{
		T elem = preList[i];
		i++;
		if (NULL != elem)
		{
			p = new BinaryNode<T>(elem);
			p->m_pLeft = Create(preList, n, i);
			p->m_pRight = Create(preList, n, i);
		}
	}

	return p;
}

// 用先序序列和中序序列创建唯一二叉树
// 原理：
// 1.先序序列的第一个结点是根节点preList[preStart]，循环中序序列找到根节点的位置i。
// 2.中序序列中根节点左边的是左子树(inStart,i-1)，右边的是右子树(i+1, n)
// 3.先序序列中           左子树(preStart+1, i),     右子树(i+1, n)
// 3.左子树和右子树又分别是一棵完整二叉树，重复1
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Create(T preList[], T inList[], int preStart, int inStart, int n)
{
	BinaryNode<T>* p = nullptr;

	if (n > 0)
	{
		T elem = preList[preStart];
		p = new BinaryNode<T>(elem);

		int i = 0;

		// 找到中序序列中根节点的位置 条件：elem==inList[i]
		while (i < n && elem != inList[i])
		{
			i++;
		}
		//preList[0]是根节点，inList[i]是根节点
		//preList[]:ABDGCEFH 0 1 2 3 ... i i+1 i+2 ... n
		//inList[] :DGBAECHF 0 1 2 3 ... i i+1 i+2 ... n
		//A是根节点 i=3 第一次分割之后,左右子树如下图所示
		//pre: A B D G   | C E F H
		//in :   D G B A | E C H F
		p->m_pLeft = Create(preList, inList, preStart + 1, inStart, i);
		p->m_pRight = Create(preList, inList, preStart + 1 + i, inStart + 1 + i, n - i - 1);
	}

	return p;
}

template <class T>
void MyBinaryTreeT<T>::PrintGList()
{
	PrintGList(m_pRoot);
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PrintGList(BinaryNode<T>* node)
{
	if (node)
	{
		cout << node->m_Data;
		if (node->m_pLeft || node->m_pRight)
		{
			cout << "(";
			PrintGList(node->m_pLeft);
			cout << ",";
			PrintGList(node->m_pRight);
			cout << ")";
		}
	}
	else
	{
		cout << "^";
	}
}

template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::InsertChild(BinaryNode<T>* node, T value, bool bLeft)
{
	BinaryNode<T>* q = nullptr;

	if (node)
	{
		q = new BinaryNode<T>(value);
		if (bLeft)
		{
			q->m_pLeft = node->m_pLeft;
			node->m_pLeft = q;
		}
		else
		{
			q->m_pRight = node->m_pRight;
			node->m_pRight = q;
		}
	}
	return q;
}

template <class T>
void MyBinaryTreeT<T>::RemoveChild(BinaryNode<T>* node, bool bLeft)
{
	if (node)
	{
		if (bLeft)
		{
			Destroy(node->m_pLeft);
			node->m_pLeft = nullptr;
		}
		else
		{
			Destroy(node->m_pRight);
			node->m_pRight = nullptr;
		}
	}
}

template <class T>
void MyBinaryTreeT<T>::PreOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "非递归先序遍历二叉树：";
	while (p || !stack.IsEmpty())
	{
		// 遍历左子树
		while (p) 
		{
			cout << p->m_Data;
			stack.Push(p);
			p = p->m_pLeft;
		}//endwhile

		// 通过下一次循环中的内嵌while实现右子树遍历
		if (!stack.IsEmpty()) 
		{
			p = stack.Pop();
			p = p->m_pRight;
		}//endif
	}
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::InOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "非递归中序遍历二叉树：";
	while (p || !stack.IsEmpty())
	{
		// 遍历左子树
		while (p) 
		{
			stack.Push(p);
			p = p->m_pLeft;
		}//endwhile

		if (!stack.IsEmpty())
		{
			p = stack.Pop();
			cout << p->m_Data;
			p = p->m_pRight;		//通过下一次循环实现右子树遍历
		}//endif 

	}//endwhile
	cout << endl;
}


// 1.stack<node> 根结点压栈
// 2.stack<node> 如果结点栈不空，出栈栈顶结点p
// 3.stack<value> 结点p的值压栈
// 4.stack<node> 压栈结点p的左结点和右节点
// 5.重复2,3，4，直到栈空
// 5.stack<value> 出栈，直到栈空
template <class T>
void MyBinaryTreeT<T>::PostOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> node_stack;	// 二叉树结点堆栈
	MyLinkStackT<T> val_stack;					// 结点值堆栈
	BinaryNode<T>* p = nullptr;

	if (!m_pRoot) return;

	cout << "非递归后续遍历二叉树：";
	node_stack.Push(m_pRoot);
	while (!node_stack.IsEmpty()) 
	{
		p = node_stack.Pop();
		val_stack.Push(p->m_Data);
		
		if (p->m_pLeft)
			node_stack.Push(p->m_pLeft);
		if (p->m_pRight)
			node_stack.Push(p->m_pRight);
	}
	
	while (!val_stack.IsEmpty())
	{
		T val = val_stack.Pop();
		cout << val;
	}
	cout << endl;
}

// 层次遍历算法，借助辅助队列
// 1.访问结点p，将结点p的左、右孩子(如果有)入队
// 2.如果队列不空，出队1个结点，使p指向它，重复1，直到队列为空
template <class T>
void MyBinaryTreeT<T>::LevelOrder()
{
	MyLinkQueueT<BinaryNode<T>*> queue;
	BinaryNode<T>* p = m_pRoot;
	
	cout << "层次遍历二叉树：";
	while (p)
	{
		cout << p->m_Data;
		if (p->m_pLeft)
		{
			queue.EnQueue(p->m_pLeft);
		}
		if (p->m_pRight)
		{
			queue.EnQueue(p->m_pRight);
		}
		
		if (!queue.IsEmpty())
		{
			p = queue.DeQueue();
		}
		else
		{
			p = nullptr;
		}
	}

	cout << endl;
}

// 注意这里必须用this指针，否则会报错，找不到m_pRoot
// 模板成员函数必须要显示指定参数（ 类指针） ： this->
// https://forum.ubuntu.org.cn/viewtopic.php?t=240044
template <class T>
CompleteBinaryTree<T>::CompleteBinaryTree(T levelList[], int n)
{
	if (n > 0)
	{
		this->m_pRoot = Create(levelList, n, 0);
	}
}

template <class T>
BinaryNode<T>* CompleteBinaryTree<T>::Create(T levelList[], int n, int i)
{
	BinaryNode<T>* p = nullptr;
	if (i < n)
	{
		p = new BinaryNode<T>(levelList[i]);
		p->m_pLeft = Create(levelList, n, 2 * i + 1);
		p->m_pRight = Create(levelList, n, 2 * i + 2);
	}
	return p;
}