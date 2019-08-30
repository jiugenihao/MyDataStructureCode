/////////////////////////////////////////////////////////////////////////////////
//文件名称：MySqListT.h
//功能描述：顺序表实现的线性表
//   随机存取，插入删除慢
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

template <class T>
class MySqListT
{
public:
	MySqListT(int size = MAX_SQLIST_SIZE);
	MySqListT(T value[], int len);
	~MySqListT();

	// immutable function
	bool IsEmpty();
	int  Len();
	int  Capacity();

	// mutable
	bool Get(int pos, T& value);
	bool Set(int pos, T value);
	void Insert(int pos, T value);
	void Insert(T value);
	bool Remove(int pos, T& value);
	void Clear();

	// 如果要为类重载操作符，并将非类的项作为第一个操作数，则可以使用友元来反转操作数的顺序
	// 通过让函数成为类的友元，可以赋予该函数与类成员函数相同的访问权限
	// C++语言规定，流对象不允许复制，只能使用引用
	// 如果MySqListT<T>这里不使用引用，那么就会发生参数复制，函数执行完后，复制出来的参数需要析构
	// 但是如果是引用的话，就无需产生复制，是同一个对象的操作
	friend ostream& operator << (ostream& out, const MySqListT<T>& list)
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

