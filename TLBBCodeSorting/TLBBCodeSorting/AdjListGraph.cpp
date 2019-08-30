#include "pch.h"
#include "AdjListGraph.h"

template <class T>
AdjListGraph<T>::AdjListGraph(int size/* = MAX_ADJLIST_SIZE*/)
{
}

template <class T>
AdjListGraph<T>::AdjListGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount)
{
}

template <class T>
AdjListGraph<T>::~AdjListGraph()
{
}

template <class T>
int AdjListGraph<T>::GetVertexCount()
{
	return m_vertexCount;
}

template <class T>
bool AdjListGraph<T>::GetVertexData(int i, T& value)
{
	return false;
}

template <class T>
void AdjListGraph<T>::InsertVertex(T vertex)
{}

template <class T>
bool AdjListGraph<T>::InsertEdge(int i, int j, int weight)
{
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