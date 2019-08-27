/////////////////////////////////////////////////////////////////////////////////
// 文件名称：AdjMatrixGraph.h
// 功能描述：邻接矩阵表示的带权图类G
//          顶点集合V + 边集合E
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"
#include "EdgeT.h"
#include "MySqListT.h"


template <class T>
class AdjMatrixGraph
{
public:
	AdjMatrixGraph(int size = 10);
	AdjMatrixGraph(T vertices[], int vertCount, EdgeT<T> edges[], int edgeCount);
	~AdjMatrixGraph();

public:
	void Init(int size);	// 初始化图的邻接矩阵
	int  GetVertexCount();
	T    GetVertexData(int i);
	void InsertVertex(T vertex);
	bool InsertEdge(int i, int j, int weight);
	bool InsertEdge(EdgeT<T> edge);
	bool RemoveEdge(int i, int j, int weight);
	bool RemoveVertex(int i, T& old);

private:
	MySqListT<T>	m_vertexList;	// 顺序表存储图的定点集合，已执行构造函数
	int**			m_pAdjMatrix;	// 图的邻接矩阵，动态二维数组
	int				m_Size;			// 二维数组的容量
	int				m_vertexCount;	// 顶点数量

};

