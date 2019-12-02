/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�AdjMatrixGraph.h
// �����������ڽӾ����ʾ�Ĵ�Ȩͼ��G
//          ���㼯��V + �߼���E
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
	void Init(int size);	// ��ʼ��ͼ���ڽӾ���

public:
	int  GetVertexCount() override;					// ��ȡ�������
	bool GetVertexData(int v, T& value) override;	// ��ö��������
	int  GetFirstNeighbor(int v) override;			// ��ȡ����v��һ���ڽӶ�������
	int  GetNextNeighbor(int v, int w) override;	// ��ȡ����v��w�����һ���ڽӶ�������

	void InsertVertex(T vertex);					// ����һ������
	bool InsertEdge(int i, int j, int weight);		// ����һ����
	bool InsertEdge(EdgeT edge);					// ����һ����
	bool RemoveEdge(int i, int j);					// ɾ��һ�����ڵı�
	bool RemoveVertex(int i, T& old);				// ɾ��һ�����ڵĶ���

	void MinSpanTree_Prim(EdgeT* mst);				// ��Ȩ������ͨͼ����С��������Prim�㷨
	void MinSpanTree_Kruskal();						// ��Ȩ������ͨͼ����С��������Kruskal�㷨

	friend ostream& operator << (ostream& out, const AdjMatrixGraph<T>& graph)
	{
		out << "��Ȩ����ͼ���ڽӾ����ʾ��" << endl;
		out << "���㼯�ϣ�" << graph.m_vertexList << endl;
		out << "�ڽӾ���" << endl;
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
	MySqListT<T>	m_vertexList;	// ˳����洢ͼ�Ķ��㼯�ϣ���ִ�й��캯��
	int**			m_pAdjMatrix;	// ͼ���ڽӾ��󣬶�̬��ά����
	int				m_size;			// ��ά���������
	int				m_vertexCount;	// ��������

};
