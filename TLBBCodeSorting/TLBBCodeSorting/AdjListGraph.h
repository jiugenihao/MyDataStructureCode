/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�AdjListGraph.h
// �����������ڽӱ��ʾ�Ĵ�Ȩͼ��G
//         ����� --- ˳���洢ͼ�����еĶ���Ԫ��
//		   �߱� --- ������洢�붥��������Ķ�����
//         ÿ�����㶼����һ������ߵ�����
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
	int  GetVertexCount();						// ��ȡ�������
	bool GetVertexData(int i, T& value);		// ��ö��������
	void InsertVertex(T vertex);				// ����һ������
	bool InsertEdge(int i, int j, int weight);	// ����һ����
	bool InsertEdge(EdgeT edge);				// ����һ����
	bool RemoveEdge(int i, int j);				// ɾ��һ�����ڵı�
	bool RemoveVertex(int i, T& old);			// ɾ��һ�����ڵĶ���

	friend ostream& operator << (ostream& out, AdjListGraph<T>& graph)
	{
		out << "��Ȩ����ͼ���ڽӱ��ʾ��" << endl;
		
		return out;
	}
private:
	Vertex<T>*	m_pVertexList;		// ���������
	int			m_size;				// �������������
	int			m_vertexCount;		// ������
};

