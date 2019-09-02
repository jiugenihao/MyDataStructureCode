#include "pch.h"
#include "AdjListGraph.h"

template <class T>
AdjListGraph<T>::AdjListGraph(int size/* = MAX_ADJLIST_SIZE*/)
{
	this->m_size = size > MAX_ADJLIST_SIZE ? size : MAX_ADJLIST_SIZE;
	this->m_pVertexList = new Vertex<T>[this->m_size];
	this->m_vertexCount = 0;
}

template <class T>
AdjListGraph<T>::AdjListGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount)
{
	this->m_size = vertCount > MAX_ADJLIST_SIZE ? vertCount : MAX_ADJLIST_SIZE;
	this->m_pVertexList = new Vertex<T>[this->m_size];
	this->m_vertexCount = 0;
	for (int i = 0; i < vertCount; ++i)
	{
		this->InsertVertex(vertices[i]);
	}
	for (int j = 0; j < edgeCount; j++)
	{
		this->InsertEdge(edges[j]);
	}
}

template <class T>
AdjListGraph<T>::~AdjListGraph()
{
	SAFE_DELETE_ARRAY(m_pVertexList);
}

template <class T>
int AdjListGraph<T>::GetVertexCount()
{
	return m_vertexCount;
}

template <class T>
bool AdjListGraph<T>::GetVertexData(int i, T& value)
{
	if (0 <= i && i < this->m_vertexCount)
	{
		value = m_pVertexList[i].m_data;
		return true;
	}
	return false;
}

template <class T>
void AdjListGraph<T>::InsertVertex(T vertex)
{
	if (this->m_vertexCount == m_size)
	{
		Vertex<T>* tmp = this->m_pVertexList;
		m_pVertexList = new Vertex<T>[m_size * 2];
		for (int i = 0; i < m_size; i++)
		{
			m_pVertexList[i] = tmp[i];
		}
		m_size *= 2;
	}

	m_pVertexList[m_vertexCount].m_data = vertex;
	this->m_vertexCount++;
}

// 按终点升序
template <class T>
bool AdjListGraph<T>::InsertEdge(int i, int j, int weight)
{
	if (0 <= i && i < this->m_vertexCount && 0 <= j && j < this->m_vertexCount && i != j)
	{
		EdgeT edge(i, j, weight);
		LinkListNode<EdgeT>* pInsert = new LinkListNode<EdgeT>(edge);
		LinkListNode<EdgeT>* pNode = this->m_pVertexList[i].m_pAdjLink.GetRoot();
		LinkListNode<EdgeT>* pFront = nullptr;
		if (!pNode)
		{
			this->m_pVertexList[i].m_pAdjLink.SetRoot(pInsert);
			return true;
		}
		else
		{
			// 头结点插入
			if (j < pNode->m_Data.m_dest)
			{
				pInsert->m_pNext = pNode;
				this->m_pVertexList[i].m_pAdjLink.SetRoot(pInsert);
				return true;
			}
			
			do
			{
				if (j == pNode->m_Data.m_dest)
				{
					return false;
				}
				pFront = pNode;
				pNode = pNode->m_pNext;
			} while (j < pNode->m_Data.m_dest);
		}
	}
	
	return false;
}

template <class T>
bool AdjListGraph<T>::InsertEdge(EdgeT edge)
{
	return false;
}

template <class T>
bool AdjListGraph<T>::RemoveEdge(int i, int j)
{
	return false;
}

template <class T>
bool AdjListGraph<T>::RemoveVertex(int i, T& old)
{
	return false;
}