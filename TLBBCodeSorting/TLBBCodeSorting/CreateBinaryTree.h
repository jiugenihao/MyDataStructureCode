/////////////////////////////////////////
//文件名称：CreateBinaryTree.h
//功能描述：创建二叉树
//        
/////////////////////////////////////////

#pragma once

#include "MyBinaryTreeT.h"

namespace Question
{
	// 创建一个char类型的二叉树
	//            A
	//           / \
	//          B   C
	//         /   / \
	//        D   E   F
	//         \     /
	//          G   H
	// 缺点：1.只能按照一种规则创建一种特定的二叉树，无通用性
	//      2.执行析构会重复释放空间(有待商榷)
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
