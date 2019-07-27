/////////////////////////////////////////
//�ļ����ƣ�CreateBinaryTree.h
//��������������������
//        
/////////////////////////////////////////

#pragma once

#include "MyBinaryTreeT.h"

namespace Question
{
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
	void CreateCharBiT(MyBinaryTreeT<char>& bittree)
	{
		BinaryNode<char>* child_G = new BinaryNode<char>('G');
		BinaryNode<char>* child_D = new BinaryNode<char>('D', nullptr, child_G);
		BinaryNode<char>* child_B = new BinaryNode<char>('B', child_D);
		
		BinaryNode<char>* child_H = new BinaryNode<char>('H');
		BinaryNode<char>* child_F = new BinaryNode<char>('F', child_H);
		BinaryNode<char>* child_E = new BinaryNode<char>('E');
		BinaryNode<char>* child_C = new BinaryNode<char>('C', child_E, child_F);

		BinaryNode<char>* child_A = new BinaryNode<char>('A', child_B, child_C);
		bittree.SetRoot(child_A);
	}
}
