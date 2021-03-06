/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyIntList.h
//功能描述：利用数组实现的列表
//   查找速度快，插入删除要移动列表，速度慢
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

//template <typename T>
class MyIntList
{
public:
	MyIntList(int maxSize = MAX_LIST_SIZE);
	~MyIntList();

	void Clear();
	bool IsEmpty();
	bool IsFull();
	int  GetSize();
	bool GetElem(int pos, int& elem);
	bool Find(int elem, int& pos);
	bool GetPriorElem(int cur, int& prior);
	bool GetNextElem(int cur, int& next);
	bool Insert(int pos, int elem);
	bool Remove(int pos, int& elem);
	void Traverse();
	void Print();

	int operator[](int pos);
	

private:
	int* m_pData;
	int m_nMaxSize;
	int m_nSize;
};

