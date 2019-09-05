/////////////////////////////////////////////////////////////////////////////////
// 文件名称：AbstractGraph.h
// 功能描述：图基类
//         
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

template <class T>
class AbstractGraph
{
public:
	virtual int  GetVertexCount() = 0;						// 获取顶点个数
	virtual bool GetVertexData(int v, T& value) = 0;		// 获得顶点的数据
	virtual int	 GetFirstNeighbor(int v) = 0;				// 返回顶点v的第一个邻接顶点的序号w
	virtual int  GetNextNeighbor(int v, int w) = 0;			// 返回顶点v在w后的下一个邻接顶点的序号

public:
	void DFSTraverse(int v);								// 从顶点v出发对非连通图进行一次深度优先搜索遍历
	void BFSTraverse(int v);								// 从顶点v出发对非连通图进行一次广度优先搜索遍历

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
		// 从顶点v开始，深度遍历v的邻接点
		if (!visited[i])
		{
			cout << "{ ";
			DFSTraverse(i, visited);
			cout << "}";
		}

		// 在其他连通分量中寻找未被访问的顶点
		i = (i + 1) % this->GetVertexCount();

	} while (i != v); // (i!=v) == true 继续循环

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

	// 获取第一个邻接点序号
	int w = this->GetFirstNeighbor(v);
	while (-1 != w)
	{
		if (!bVisited[w])
		{
			// 从w出发的深度优先遍历，递归调用
			DFSTraverse(w, bVisited);
		}
		w = this->GetNextNeighbor(v, w);
	}
}

template<class T>
inline void AbstractGraph<T>::BFSTraverse(int v, bool bVisited[])
{
}
