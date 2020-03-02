/////////////////////////////////////////
//文件名称：Question1.h
//算法题1：在一个数组中查找任意个数和为m的组合
//        
/////////////////////////////////////////

#pragma once

#include "BaseDefine.h"
#include "SortUtility.h"

namespace Question
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// 算法描述
	// 给定一个序列，查找任意两个数之和为M的所有组合
	// list   为给定序列
	// limit  为两数之和
	// 缺点：如果序列中有重复数据，会错过
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	
	void FindResult(int list[], int len, int limit)
	{
		// 1.先将序列从小到大排序
		SortUtility::QuickSort(list, len);

		// 2.查找 a + b = limit
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
