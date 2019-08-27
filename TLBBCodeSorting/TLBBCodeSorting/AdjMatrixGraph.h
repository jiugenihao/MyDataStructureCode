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
	AdjMatrixGraph(int size = 10);
	AdjMatrixGraph(T vertices[], int vertCount, EdgeT<T> edges[], int edgeCount);
	~AdjMatrixGraph();

public:
	void Init(int size);	// ��ʼ��ͼ���ڽӾ���
	int  GetVertexCount();
	T    GetVertexData(int i);
	void InsertVertex(T vertex);
	bool InsertEdge(int i, int j, int weight);
	bool InsertEdge(EdgeT<T> edge);
	bool RemoveEdge(int i, int j, int weight);
	bool RemoveVertex(int i, T& old);

private:
	MySqListT<T>	m_vertexList;	// ˳���洢ͼ�Ķ��㼯�ϣ���ִ�й��캯��
	int**			m_pAdjMatrix;	// ͼ���ڽӾ��󣬶�̬��ά����
	int				m_Size;			// ��ά���������
	int				m_vertexCount;	// ��������

};

