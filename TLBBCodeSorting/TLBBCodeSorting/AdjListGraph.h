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
	int  GetVertexCount() override;					// ��ȡ�������
	bool GetVertexData(int v, T& value) override;	// ��ö��������
	int  GetFirstNeighbor(int v) override;			// ��ȡ����v��һ���ڽӶ�������
	int  GetNextNeighbor(int v, int w) override;	// ��ȡ����v��w�����һ���ڽӶ�������

	void InsertVertex(T vertex);					// ����һ������
	bool InsertEdge(int i, int j, int weight);		// ����һ����
	bool InsertEdge(EdgeT edge);					// ����һ����
	bool RemoveEdge(int i, int j);					// ɾ��һ�����ڵı�
	bool RemoveVertex(int v, T& old);				// ɾ��һ�����ڵĶ���
	

	friend ostream& operator << (ostream& out, const AdjListGraph<T>& graph)
	{
		for (int i = 0; i < graph.m_vertexCount; i++)
		{
			out << "����[" << i << "] :" << graph.m_pVertexList[i].m_data << endl;
			if (graph.m_pVertexList[i].m_pAdjLink.IsEmpty())
				out << "���߱�:" << " ()";
			else
				out << "���߱�:" << graph.m_pVertexList[i].m_pAdjLink;
		}
		return out;
	}
private:
	Vertex<T>*	m_pVertexList;		// ���������
	int			m_size;				// �������������
	int			m_vertexCount;		// ������
};

