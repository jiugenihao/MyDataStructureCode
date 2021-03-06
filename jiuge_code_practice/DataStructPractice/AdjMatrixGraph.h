/////////////////////////////////////////////////////////////////////////////////
// 文件名称：AdjMatrixGraph.h
// 功能描述：邻接矩阵表示的带权图类G
//          顶点集合V + 边集合E
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"
#include "EdgeT.h"
#include "MySqListT.h"
#include "AbstractGraph.h"

template <class T>
class AdjMatrixGraph : public AbstractGraph<T>
{
public:
	AdjMatrixGraph(int size = MAX_ADJMATRIX_SIZE);
	AdjMatrixGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount);
	~AdjMatrixGraph();

private:
	void Init(int size);	// 初始化图的邻接矩阵

public:
	int  GetVertexCount() override;					// 获取顶点个数
	bool GetVertexData(int v, T& value) override;	// 获得顶点的数据
	int  GetFirstNeighbor(int v) override;			// 获取顶点v第一个邻接顶点的序号
	int  GetNextNeighbor(int v, int w) override;	// 获取顶点v在w后的下一个邻接顶点的序号

	void InsertVertex(T vertex);					// 插入一个顶点
	bool InsertEdge(int i, int j, int weight);		// 插入一条边
	bool InsertEdge(EdgeT edge);					// 插入一条边
	bool RemoveEdge(int i, int j);					// 删除一条存在的边
	bool RemoveVertex(int i, T& old);				// 删除一个存在的顶点

	void MinSpanTree_Prim(EdgeT* mst);				// 带权无相连通图的最小生成树的Prim算法
	void MinSpanTree_Kruskal();						// 带权无相连通图的最小生成树的Kruskal算法

	friend ostream& operator << (ostream& out, const AdjMatrixGraph<T>& graph)
	{
		out << "带权无向图的邻接矩阵表示：" << endl;
		out << "顶点集合：" << graph.m_vertexList << endl;
		out << "邻接矩阵：" << endl;
		int n = graph.m_vertexCount;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (MAX_WEIGHT == graph.m_pAdjMatrix[i][j])
				{
					out << " *";
				}
				else
				{
					out << " " << graph.m_pAdjMatrix[i][j];
				}
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

