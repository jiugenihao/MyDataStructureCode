/////////////////////////////////////////
//�ļ����ƣ�LinearListSearch.h
//�������������Ա�����㷨
//        
/////////////////////////////////////////

#pragma once
#include "BaseDefine.h"

namespace SearchUtility
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// ˳�����
	// ˳���int MySqListT<T>::Index(T value)
	// ������LinkListNode<T>* MySinglyLinkedListT<T>::Search(T value)
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
	// ���ֲ���
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	bool BinarySearch(T sort_list[], int len, T value)
	{
		return false;
	}
}