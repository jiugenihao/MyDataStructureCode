/////////////////////////////////////////
//�ļ����ƣ�CreateBinaryTree.h
//��������������������
//        
/////////////////////////////////////////

#pragma once

#include "MyBinaryTreeT.h"

namespace Question
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// ����һ��char���͵Ķ�����
	//            A
	//           / \
	//          B   C
	//         /   / \
	//        D   E   F
	//         \     /
	//          G   H
	// ȱ�㣺1.ֻ�ܰ���һ�ֹ��򴴽�һ���ض��Ķ���������ͨ����
	//      2.ִ���������ظ��ͷſռ�(�д���ȶ)
	// 
	// ����ABDGCEFH
	// ����DGBAECHF
	// ����GDBEHFCA
	//
	// ���������������ʾ��ABD^G^^^CE^^FH^^^
	// ������ʾ��A(B(D(^,G),^),C(E,F(H,^)))
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	void CreateCharBiT(MyBinaryTreeT<char>& bitTree)
	{
		BinaryNode<char>* child_G = new BinaryNode<char>('G');
		BinaryNode<char>* child_D = new BinaryNode<char>('D', nullptr, child_G);
		BinaryNode<char>* child_B = new BinaryNode<char>('B', child_D);
		
		BinaryNode<char>* child_H = new BinaryNode<char>('H');
		BinaryNode<char>* child_F = new BinaryNode<char>('F', child_H);
		BinaryNode<char>* child_E = new BinaryNode<char>('E');
		BinaryNode<char>* child_C = new BinaryNode<char>('C', child_E, child_F);

		BinaryNode<char>* child_A = new BinaryNode<char>('A', child_B, child_C);
		bitTree.SetRoot(child_A);
	}

	BinaryNode<char>* CreateBiTByGList(char gList[], int& i)
	{
		BinaryNode<char>* p = nullptr;

		if (gList[i] >= 'A' && gList[i] <= 'Z')
		{
			p = new BinaryNode<char>(gList[i]);
			i++;
			if (gList[i] == '(')
			{
				i++;	// ����������
				p->m_pLeft = CreateBiTByGList(gList, i);
				i++;	// ��������
				p->m_pRight = CreateBiTByGList(gList, i);
				i++;	// ����������
			}
		}

		if (gList[i] == '^')
		{
			i++;
		}

		return p;
	}

	void CreateBiTByGList(MyBinaryTreeT<char>& bitTree, char gList[])
	{
		int i = 0;
		bitTree.SetRoot(CreateBiTByGList(gList, i));
	}

	
}
