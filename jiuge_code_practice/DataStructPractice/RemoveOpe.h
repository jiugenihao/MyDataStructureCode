/////////////////////////////////////////
//文件名称：RemoveOpe.h
//功能描述：删除操作
//        
/////////////////////////////////////////

#pragma once
#include "BaseDefine.h"

namespace Question
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// 问题：删除线性表中所有值为value的元素
	//+++++++++++++++++++++++++++++++++++++++++++++++++//

	// 老王的方法，优点遍历次数少，缺点不易读
	int RemoveAll_lw(int data[], int n, int value)
	{
		if (n <= 0) return -1;

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		int removeCnt = 0;
		int loop = 0;		// 循环次数
		
		for (int i = 0; i < n - 1; i++)
		{
			loop++;
			if (data[i] == value)
			{
				for (; i < n - 1; ++i)
				{
					loop++;
					if (data[i + 1] == value)
						removeCnt++;
					else
						break;
				}
				removeCnt++;
			}
			if (removeCnt > 0)
			{
				data[i - removeCnt + 1] = data[i + 1];
			}
		}
		if (data[n - 1] == value)
			data[n - removeCnt - 1] = 0;
		for (int i = n - removeCnt; i < n; i++)
		{
			data[i] = 0;
			loop++;
		}

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		return loop;
	}

	// 我的方法，缺点遍历次数多，优点易读，返回长度
	int RemoveAll_me(int data[], int& n, int value)
	{
		int loop = 0;
		
		if (n <= 0) return -1;

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		for (int i = n - 1; i >= 0; --i)
		{
			loop++;
			if (data[i] == value)
			{
				for (int j = i; j < n; ++j)
				{
					loop++;
					data[j] = data[j + 1];
				}
				n--;
			}
		}

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		return loop;
	}

	// 曾总的，遍历次数少，易读，
	int RemoveAll_zq(int data[], int n, int value)
	{
		if (n <= 0) return -1;

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		int loop = 0;
		int index = 0;
		for (int i = 0; i < n - 1; i++)
		{
			loop++;
			if (data[i] != value)
				data[index++] = data[i];
		}
		for (int i = index; i < n - 1; i++)
		{
			loop++;
			data[i] = value;	// 这一步保留了删除的值，有待商榷
		}

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		return loop;
	}

}
