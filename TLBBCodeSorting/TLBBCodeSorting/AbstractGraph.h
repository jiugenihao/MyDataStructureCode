/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�AbstractGraph.h
// ����������ͼ����
//         
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

template <class T>
class AbstractGraph
{
public:
	virtual int  GetVertexCount() = 0;						// ��ȡ�������
	virtual bool GetVertexData(int v, T& value) = 0;		// ��ö��������
	virtual int	 GetFirstNeighbor(int v) = 0;				// ���ض���v�ĵ�һ���ڽӶ�������w
	virtual int  GetNextNeighbor(int v, int w) = 0;			// ���ض���v��w�����һ���ڽӶ�������

public:
	void DFSTraverse(int v);								// �Ӷ���v�����Է���ͨͼ����һ�����������������
	void BFSTraverse(int v);								// �Ӷ���v�����Է���ͨͼ����һ�ι��������������

private:
	void DFSTraverse(int v, bool bVisited[]);
	void BFSTraverse(int v, bool bVisited[]);
};


template<class T>
inline void AbstractGraph<T>::DFSTraverse(int v)
{
	bool* visited = new bool[this->GetVertexCount()];
	int i = 0;
	for (i = 0; i < this->GetVertexCount(); i++)
	{
		visited[i] = false;
	}
	i = v;
	do
	{
		// �Ӷ���v��ʼ����ȱ���v���ڽӵ�
		if (!visited[i])
		{
			cout << "{ ";
			DFSTraverse(i, visited);
			cout << "}";
		}

		// ��������ͨ������Ѱ��δ�����ʵĶ���
		i = (i + 1) % this->GetVertexCount();

	} while (i != v); // (i!=v) == true ����ѭ��

	cout << endl;
	delete[] visited;
}

template<class T>
inline void AbstractGraph<T>::BFSTraverse(int v)
{
}

template<class T>
inline void AbstractGraph<T>::DFSTraverse(int v, bool bVisited[])
{
	T vertInfo;
	this->GetVertexData(v, vertInfo);
	cout << vertInfo << " ";
	bVisited[v] = true;

	// ��ȡ��һ���ڽӵ����
	int w = this->GetFirstNeighbor(v);
	while (-1 != w)
	{
		if (!bVisited[w])
		{
			// ��w������������ȱ������ݹ����
			DFSTraverse(w, bVisited);
		}
		w = this->GetNextNeighbor(v, w);
	}
}

template<class T>
inline void AbstractGraph<T>::BFSTraverse(int v, bool bVisited[])
{
}
