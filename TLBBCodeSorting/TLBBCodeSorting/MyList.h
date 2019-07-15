/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyList.h
//功能描述：利用数组实现的列表
//   查找速度快，插入删除要移动列表，速度慢
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#define MAX_LIST_SIZE 5

//template <typename T>
class MyList
{
public:
	MyList(int maxSize = MAX_LIST_SIZE);
	~MyList();

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

