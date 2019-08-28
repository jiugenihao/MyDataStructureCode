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
	AdjMatrixGraph(int size = MAX_ADJMATRIX_SIZE);
	AdjMatrixGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount);
	~AdjMatrixGraph();

private:
	void Init(int size);	// 初始化图的邻接矩阵

public:
	int  GetVertexCount();
	bool GetVertexData(int i, T& value);
	void InsertVertex(T vertex);
	bool InsertEdge(int i, int j, int weight);
	bool InsertEdge(EdgeT edge);
	bool RemoveEdge(int i, int j, int weight);
	bool RemoveVertex(int i, T& old);

	friend ostream& operator << (ostream& out, AdjMatrixGraph<T>& graph)
	{
		out << "顶点集合：" << graph.m_vertexList << endl;
		out << "邻接矩阵：" << endl;
		int n = graph.m_vertexCount;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (MAX_WEIGHT == graph.m_pAdjMatrix[i][j])
				{
					out << " *";
				}
				out << " " << graph.m_pAdjMatrix[i][j];
			}
			out << endl;
		}
		return out;
	}

private:
	MySqListT<T>	m_vertexList;	// 顺序表存储图的定点集合，已执行构造函数
	int**			m_pAdjMatrix;	// 图的邻接矩阵，动态二维数组
	int				m_size;			// 二维数组的容量
	int				m_vertexCount;	// 顶点数量

};

