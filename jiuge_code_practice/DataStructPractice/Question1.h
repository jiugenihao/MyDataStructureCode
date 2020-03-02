/////////////////////////////////////////
//�ļ����ƣ�Question1.h
//�㷨��1����һ�������в������������Ϊm�����
//        
/////////////////////////////////////////

#pragma once

#include "BaseDefine.h"
#include "SortUtility.h"

namespace Question
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// �㷨����
	// ����һ�����У���������������֮��ΪM���������
	// list   Ϊ��������
	// limit  Ϊ����֮��
	// ȱ�㣺������������ظ����ݣ�����
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	
	void FindResult(int list[], int len, int limit)
	{
		// 1.�Ƚ����д�С��������
		SortUtility::QuickSort(list, len);

		// 2.���� a + b = limit
		int start = 0;
		int end = len - 1;
		if (list[start] >= limit)
		{
			cout << "No Result ..." << endl;
			return;
		}
		cout << "All Result are :" << endl;
		while (start < end)
		{
			if (list[start] + list[end] == limit)
			{
				cout << list[start] << "+" << list[end] << "=" << limit << endl;
				start++;
				end--;
			} 
			else if (list[start] + list[end] > limit)
			{
				end--;
			} 
			else
			{
				start++;
			}
		}
	}
}
