/////////////////////////////////////////////////////////////////////////////////
// 文件名称：AdjListGraph.h
// 功能描述：邻接表表示的带权图类G
//         顶点表 --- 顺序表存储图中所有的顶点元素
//		   边表 --- 单链表存储与顶点相关联的多条边
//         每个顶点都关联一条保存边的链表
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"
#include "EdgeT.h"
#include "MyLinkedListT.h"

template <class T>
class Vertex
{
public:
	Vertex(){}
	~Vertex() {}

public:
	T m_data;
	MySinglyLinkedListT<EdgeT> m_pAdjLink;
};


template <class T>
class AdjListGraph
{
public:
	AdjListGraph(int size = MAX_ADJLIST_SIZE);
	AdjListGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount);
	~AdjListGraph();

public:
	int  GetVertexCount();						// 获取顶点个数
	bool GetVertexData(int i, T& value);		// 获得顶点的数据
	void InsertVertex(T vertex);				// 插入一个顶点
	bool InsertEdge(int i, int j, int weight);	// 插入一条边
	bool InsertEdge(EdgeT edge);				// 插入一条边
	bool RemoveEdge(int i, int j);				// 删除一条存在的边
	bool RemoveVertex(int i, T& old);			// 删除一个存在的顶点

	friend ostream& operator << (ostream& out, AdjListGraph<T>& graph)
	{
		out << "带权无向图的邻接表表示：" << endl;
		
		return out;
	}
private:
	Vertex<T>*	m_pVertexList;		// 顶点表数组
	int			m_size;				// 顶点表数组容量
	int			m_vertexCount;		// 顶点数
};

