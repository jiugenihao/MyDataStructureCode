#include "pch.h"
#include "MyBinaryTreeT.h"

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT()
{
	m_pRoot = nullptr;
}

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT(T prelist[], int n)
{
	int i = 0;
	m_pRoot = Create(prelist, n, i);
}

template <class T>
MyBinaryTreeT<T>::MyBinaryTreeT(T prelist[], T inlist[], int n)
{
	
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

// ���������ɾ������ɾ���ҽ����ɾ����
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
	cout << "���������������";
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
	cout << "���������������";
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
	cout << "���������������";
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

// ���ú����α���
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

// ���������������
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

// �������������ȡ
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
		cout << value << "�����Ƚ���ǣ�";
		BinaryNode<T>* parent = GetParent(find);
		while (parent)
		{
			cout << parent->m_Data << " ";
			parent = GetParent(parent);
		}
		cout << endl;
	}
	else
		cout << "û���ҵ��ý��" << endl;
}

// �ñ������������������д������������ȹ������������ٹ���������
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