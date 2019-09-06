/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�AbstractGraph.h
// ����������ͼ����
//         ������ȱ���DFS---��v����һ��·�ߵ��ڣ��������û�߹��ģ���ô��������㣬������
//		   ������ȱ���BFS---����ˮ����ʯͷ����һ��������v���������⼤��������������ɢ
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"
#include "MySqQueueT.h"

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
	cout << "������ȱ�����" << endl;
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
	cout << "������ȱ�����" << endl;
	bool* visited = new bool[this->GetVertexCount()];
	int i = 0;
	for (i = 0; i < this->GetVertexCount(); i++)
	{
		visited[i] = false;
	}
	i = v;
	do
	{
		if (!visited[i])
		{
			cout << "{ ";
			BFSTraverse(i, visited);
			cout << "}";
		}
		i = (i + 1) % this->GetVertexCount();
	} while (i != v);

	cout << endl;
	delete[] visited;
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
	T vertInfo;
	this->GetVertexData(v, vertInfo);
	cout << vertInfo << " ";
	bVisited[v] = true;

	MySqQueueT<int> queue(this->GetVertexCount());
	queue.EnQueue(v);

	while (!queue.IsEmpty())
	{
		int v = queue.DeQueue();
		int w = this->GetFirstNeighbor(v);
		while (-1 != w)
		{
			if (!bVisited[w])
			{
				T vertInfo2;
				this->GetVertexData(w, vertInfo2);
				cout << vertInfo2 << " ";
				bVisited[w] = true;

				queue.EnQueue(w);
			}
			w = this->GetNextNeighbor(v, w);
		}
	}
}
