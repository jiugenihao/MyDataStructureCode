/////////////////////////////////////////
//文件名称：LinearListSearch.h
//功能描述：线性表查找算法
//        
/////////////////////////////////////////

#pragma once
#include "BaseDefine.h"

namespace SearchUtility
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// 顺序查找
	// 顺序表：int MySqListT<T>::Index(T value)
	// 单链表：LinkListNode<T>* MySinglyLinkedListT<T>::Search(T value)
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	int LinearSearch(T list[], int len, T key)
	{
		if (len <= 0)
			return -1;
		for (int i = 0; i < len; ++i)
		{
			if (list[i] == key)
				return i;
		}
		return -1;
	}

	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// 二分查找
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	bool BinarySearch(T sort_list[], int len, T value)
	{
		return false;
	}
}