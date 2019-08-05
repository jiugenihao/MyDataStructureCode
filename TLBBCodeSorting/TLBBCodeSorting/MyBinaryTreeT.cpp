#include "pch.h"
#include "MyBinaryTreeT.h"
#include "MyLinkStackT.h"

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

// ���������к��������д���Ψһ������
// ԭ��
// 1.�������еĵ�һ������Ǹ��ڵ�preList[preStart]��ѭ�����������ҵ����ڵ��λ��i��
// 2.���������и��ڵ���ߵ���������(inStart,i-1)���ұߵ���������(i+1, n)
// 3.����������           ������(preStart+1, i),     ������(i+1, n)
// 3.���������������ֱַ���һ���������������ظ�1
template <class T>
BinaryNode<T>* MyBinaryTreeT<T>::Create(T preList[], T inList[], int preStart, int inStart, int n)
{
	BinaryNode<T>* p = nullptr;

	if (n > 0)
	{
		T elem = preList[preStart];
		p = new BinaryNode<T>(elem);

		int i = 0;

		// �ҵ����������и��ڵ��λ�� ������elem==inList[i]
		while (i < n && elem != inList[i])
		{
			i++;
		}
		//preList[0]�Ǹ��ڵ㣬inList[i]�Ǹ��ڵ�
		//preList[]:ABDGCEFH 0 1 2 3 ... i i+1 i+2 ... n
		//inList[] :DGBAECHF 0 1 2 3 ... i i+1 i+2 ... n
		//A�Ǹ��ڵ� i=3 ��һ�ηָ�֮��,������������ͼ��ʾ
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
void MyBinaryTreeT<T>::PreOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "�ǵݹ����������������";
	while (p || !stack.IsEmpty())
	{
		// ����������
		while (p) 
		{
			cout << p->m_Data;
			stack.Push(p);
			p = p->m_pLeft;
		}//endwhile

		// ͨ����һ��ѭ���е���Ƕwhileʵ������������
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

	cout << "�ǵݹ����������������";
	while (p || !stack.IsEmpty())
	{
		// ����������
		while (p) 
		{
			stack.Push(p);
			p = p->m_pLeft;
		}//endwhile

		if (!stack.IsEmpty())
		{
			p = stack.Pop();
			cout << p->m_Data;
			p = p->m_pRight;		//ͨ����һ��ѭ��ʵ������������
		}//endif 

	}//endwhile
	cout << endl;
}

template <class T>
void MyBinaryTreeT<T>::PostOrderTraverse()
{
	MyLinkStackT<BinaryNode<T>*> stack;
	BinaryNode<T>* p = m_pRoot;

	cout << "�ǵݹ��������������";

	int  Tag[20];       // ջ�����ڱ�ʶ����0�����ң�1������  
	//while (p || !stack.IsEmpty())
	//{
	//	while (p)
	//	{
	//		stack.Push(p);
	//		Tag[stack.top] = 0;
	//		p = p->m_pLeft;
	//	}
	//	while (!isempty(st) && Tag[st->top] == 1)
	//	{
	//		p = pop(st);
	//		cout << p->data << "    ";
	//	}
	//	if (!isempty(st))
	//	{
	//		Tag[st->top] = 1;    // ���ñ���������Ѿ�����  
	//		p = gettop(st);
	//		p = p->rchild;
	//	}
	//	else   
	//		break;
	//}
	//do
	//{
	//	while (p) //����������
	//	{
	//		x.ptr = p;
	//		x.tag = L; //���Ϊ������
	//		push(s, x);
	//		p = p->lchild;
	//	}

	//	while (!StackEmpty(s) && s.Elem[s.top].tag == R)
	//	{
	//		x = pop(s);
	//		p = x.ptr;
	//		visite(p->data); //tagΪR����ʾ������������ϣ��ʷ��ʸ���� 
	//	}

	//	if (!StackEmpty(s))
	//	{
	//		s.Elem[s.top].tag = R; //����������
	//		p = s.Elem[s.top].ptr->rchild;
	//	}
	//} while (!StackEmpty(s));
}