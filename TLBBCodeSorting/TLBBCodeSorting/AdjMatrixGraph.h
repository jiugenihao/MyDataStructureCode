/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�AdjMatrixGraph.h
// �����������ڽӾ����ʾ�Ĵ�Ȩͼ��G
//          ���㼯��V + �߼���E
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
	void Init(int size);	// ��ʼ��ͼ���ڽӾ���

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
		out << "���㼯�ϣ�" << graph.m_vertexList << endl;
		out << "�ڽӾ���" << endl;
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
	MySqListT<T>	m_vertexList;	// ˳���洢ͼ�Ķ��㼯�ϣ���ִ�й��캯��
	int**			m_pAdjMatrix;	// ͼ���ڽӾ��󣬶�̬��ά����
	int				m_size;			// ��ά���������
	int				m_vertexCount;	// ��������

};

