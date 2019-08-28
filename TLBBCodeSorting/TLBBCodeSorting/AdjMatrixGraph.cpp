#include "pch.h"
#include "AdjMatrixGraph.h"

template <class T>
AdjMatrixGraph<T>::AdjMatrixGraph(int size /*= MAX_ADJMATRIX_SIZE*/)
{
    this->Init(size);
}

template <class T>
AdjMatrixGraph<T>::AdjMatrixGraph(T vertices[], int vertCount, EdgeT edges[], int edgeCount)
{
    this->Init(vertCount);
    for (size_t i = 0; i < vertCount; i++)
    {
        this->InsertVertex(vertices[i]);
    }
    for (size_t j = 0; j < edgeCount; j++)
    {
        this->InsertEdge(edges[j]);
    }
    
}

template <class T>
AdjMatrixGraph<T>::~AdjMatrixGraph()
{
    for (size_t i = 0; i < m_size; i++)
    {
        SAFE_DELETE_ARRAY(m_pAdjMatrix[i]);
    }
    SAFE_DELETE_ARRAY(m_pAdjMatrix);
}

template <class T>
void AdjMatrixGraph<T>::Init(int size)
{
    this->m_size = size < MAX_ADJMATRIX_SIZE ? MAX_ADJMATRIX_SIZE : size;
    this->m_pAdjMatrix = new int*[this->m_size];
    for (size_t i = 0; i < this->m_size; i++)
    {
        this->m_pAdjMatrix[i] = new int[this->m_size];
        for (size_t j = 0; j < this->m_size; j++)
        {
            this->m_pAdjMatrix[i][j] = (i==j) ? 0 : MAX_WEIGHT;
        }
    }
    this->m_vertexCount = 0;
}

template <class T>
int AdjMatrixGraph<T>::GetVertexCount()
{
    return m_vertexCount;
}

template <class T>
bool AdjMatrixGraph<T>::GetVertexData(int i, T& value)
{
    return m_vertexList.Get(i, value);
}