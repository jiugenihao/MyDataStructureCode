#include "pch.h"
#include "MyList.h"
#include "BaseDefine.h"

MyList::MyList(int maxSize):m_nMaxSize(maxSize)
{
	m_pData = new int[m_nMaxSize]();
	//for (int i = 0; i < m_nMaxSize; ++i)
	//{
	//	m_pData[i].nData = 0;
	//	//m_pData[i].next = nullptr;
	//}
	m_nSize = 0;
}


MyList::~MyList()
{
	SAFE_DELETE_ARRAY(m_pData);
}

void MyList::Clear()
{
	for (int i = 0; i < m_nSize; ++i)
	{
		m_pData[i] = 0;
	}
	m_nSize = 0;
}

bool MyList::IsEmpty()
{
	return (m_nSize == 0);
}

bool MyList::IsFull()
{
	return (m_nSize == m_nMaxSize);
}

int MyList::GetSize()
{
	return m_nSize;
}

bool MyList::GetElem(int pos, int& elem)
{
	if (pos < 0 || pos >= m_nSize)
	{
		return false;
	}
	elem = m_pData[pos];
	return true;
}

int MyList::operator[](int pos)
{
	if (pos < 0 || pos >= m_nSize)
	{
		return 0;
	}

	return m_pData[pos];
}

bool MyList::Find(int elem, int& pos)
{
	for (int i = 0; i < m_nSize; ++i)
	{
		if (m_pData[i] == elem)
		{
			pos = i;
			return true;
		}
	}

	return false;
}

bool MyList::GetPriorElem(int cur, int& prior)
{
	int pos = 0;
	if (Find(cur, pos) && pos > 0)
	{
		prior = m_pData[pos - 1];
		return true;
	}

	return false;
}

bool MyList::GetNextElem(int cur, int& next)
{
	int pos = 0;
	if (Find(cur, pos) && pos < m_nSize - 1)
	{
		next = m_pData[pos + 1];
		return true;
	}
	return false;
}

// pos的前一个位置插入elem, pos...length后移 pos+1...length+1
bool MyList::Insert(int pos, int elem)
{
	if (pos < 1 || pos > m_nSize + 1)
		return false;

	if (IsFull())
		return false;

	// 后移
	for (int i = m_nSize; i >= pos; --i)
	{
		m_pData[i] = m_pData[i - 1];
	}
	//
	m_pData[pos-1] = elem;
	m_nSize++;
	return true;
}

// pos位置的元素为Elem[pos-1]
bool MyList::Remove(int pos, int& elem)
{
	if (pos < 1 || pos > m_nSize)
		return false;

	elem = m_pData[pos-1];
	for (int i = pos; i < m_nSize-1; ++i)
	{
		m_pData[i] = m_pData[i+1];
	}
	m_pData[m_nSize - 1] = 0;
	m_nSize--;
	return true;
}

void MyList::Traverse()
{

}

void MyList::Print()
{
	if (nullptr != m_pData)
	{
		cout << "The element of List:";
		for (int i = 0; i < m_nSize; ++i)
		{
			cout << m_pData[i] << " ";
		}
		cout << endl;
	}
}
