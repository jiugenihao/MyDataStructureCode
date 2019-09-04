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
			
			while (pNode && j >= pNode->m_Data.m_dest)
			{
				if (j == pNode->m_Data.m_dest)
				{
					return false;
				}
				pFront = pNode;
				pNode = pNode->m_pNext;
			}

			pInsert->m_pNext = pNode;
			pFront->m_pNext = pInsert;
			return true;
		}
	}
	
	return false;
}

template <class T>
bool AdjListGraph<T>::InsertEdge(EdgeT edge)
{
	return InsertEdge(edge.m_start, edge.m_dest, edge.m_weight);
}

template <class T>
bool AdjListGraph<T>::RemoveEdge(int i, int j)
{
	if (0 <= i && i < this->m_vertexCount && 0 <= j && j < this->m_vertexCount && i != j)
	{
		LinkListNode<EdgeT>* pNode = this->m_pVertexList[i].m_pAdjLink.GetRoot();
		LinkListNode<EdgeT>* pFront = nullptr;
		if (pNode && j == pNode->m_Data.m_dest )
		{
			this->m_pVertexList[i].m_pAdjLink.SetRoot(pNode->m_pNext);
			delete pNode;
			return true;
		}
		while (pNode && j != pNode->m_Data.m_dest)
		{
			pFront = pNode;
			pNode = pNode->m_pNext;
		}
		if (pNode)
		{
			pFront->m_pNext = pNode->m_pNext;
			delete pNode;
			return true;
		}
	}
	return false;
}

template <class T>
bool AdjListGraph<T>::RemoveVertex(int i, T& old)
{
	if (i < 0 || i > this->m_vertexCount)
	{
		return false;
	}
	// 删除此顶点的边链表 (i, dest)
	old = this->m_pVertexList[i].m_data;
	this->m_pVertexList[i].m_pAdjLink.Clear();

	// 删除此顶点作为目标点的边,也就是对称的边 (dest, i)
	LinkListNode<EdgeT>* pNode = this->m_pVertexList[i].m_pAdjLink.GetRoot();
	while (pNode)
	{
		this->RemoveEdge(pNode->m_Data.m_dest, pNode->m_Data.m_start);
		pNode = pNode->m_pNext;
	}

	// 顶点元素向前移动一行
	for (int j = i; j < this->m_vertexCount - 1; j++)
	{
		this->m_pVertexList[j].m_data = this->m_pVertexList[j + 1].m_data;
		this->m_pVertexList[j].m_pAdjLink.SetRoot(this->m_pVertexList[j + 1].m_pAdjLink.GetRoot());
		this->m_pVertexList[j + 1].m_pAdjLink.SetRoot(nullptr);
	}
	
	this->m_vertexCount--;

	// 未删除的边结点更改某些顶点序号
	for (int k = 0; k < this->m_vertexCount; k++)
	{
		pNode = this->m_pVertexList[k].m_pAdjLink.GetRoot();
		while (pNode)
		{
			if (pNode->m_Data.m_start > i)
			{
				pNode->m_Data.m_start--;
			}
			if (pNode->m_Data.m_dest > i)
			{
				pNode->m_Data.m_dest--;
			}
			pNode = pNode->m_pNext;
		}
	}

	return true;
}

template<class T>
int AdjListGraph<T>::GetFirstNeighbor(int v)
{
	return 0;
}

template<class T>
int AdjListGraph<T>::GetNextNeighbor(int v, int w)
{
	return 0;
}
