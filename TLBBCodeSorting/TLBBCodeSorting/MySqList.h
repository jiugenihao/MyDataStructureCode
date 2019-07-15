/////////////////////////////////////////////////////////////////////////////////
//文件名称：MySqList.h
//功能描述：模板顺序表，数组实现
//   随机存取，插入删除慢
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

#define MAX_SQLIST_SIZE 64

template <class T>
class MySqList
{
public:
	MySqList(int size = MAX_SQLIST_SIZE);
	MySqList(T value[], int len);
	~MySqList();

	bool IsEmpty();
	int  Len();
	int  Capacity();
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	void Insert(int pos, T value);
	void Insert(T value);
	bool Remove(int pos, T& value);
	void Clear();

	friend ostream& operator << (ostream& out, MySqList<T> list)
	{
		out << "output all elements:" << endl;
		if (list.m_Len > 0)
		{
			out << list.m_pData[0];
			for (int i = 1; i < list.m_Len; ++i)
			{
				out << "," << list.m_pData[i];
			}
			out << endl;
		}
		return out;
	}

private:
	T*	m_pData;
	int	m_Len;
	int m_Size;
};

