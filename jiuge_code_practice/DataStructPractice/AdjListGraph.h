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
#include "AbstractGraph.h"

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
class AdjListGraph : public AbstractGraph<T>
{
public:
	AdjListGraph(int size = MAX_ADJLIST_SIZE);
	AdjListGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount);
	~AdjListGraph();

public:
	int  GetVertexCount() override;					// 获取顶点个数
	bool GetVertexData(int v, T& value) override;	// 获得顶点的数据
	int  GetFirstNeighbor(int v) override;			// 获取顶点v第一个邻接顶点的序号
	int  GetNextNeighbor(int v, int w) override;	// 获取顶点v在w后的下一个邻接顶点的序号

	void InsertVertex(T vertex);					// 插入一个顶点
	bool InsertEdge(int i, int j, int weight);		// 插入一条边
	bool InsertEdge(EdgeT edge);					// 插入一条边
	bool RemoveEdge(int i, int j);					// 删除一条存在的边
	bool RemoveVertex(int v, T& old);				// 删除一个存在的顶点
	

	friend ostream& operator << (ostream& out, const AdjListGraph<T>& graph)
	{
		for (int i = 0; i < graph.m_vertexCount; i++)
		{
			out << "顶点[" << i << "] :" << graph.m_pVertexList[i].m_data << endl;
			if (graph.m_pVertexList[i].m_pAdjLink.IsEmpty())
				out << "出边表:" << " ()";
			else
				out << "出边表:" << graph.m_pVertexList[i].m_pAdjLink;
		}
		return out;
	}
private:
	Vertex<T>*	m_pVertexList;		// 顶点表数组
	int			m_size;				// 顶点表数组容量
	int			m_vertexCount;		// 顶点数
};

