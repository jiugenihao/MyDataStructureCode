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
    for (int i = 0; i < vertCount; i++)
    {
        this->InsertVertex(vertices[i]);
    }
    for (int j = 0; j < edgeCount; j++)
    {
        this->InsertEdge(edges[j]);
    }
    
}

template <class T>
AdjMatrixGraph<T>::~AdjMatrixGraph()
{
    for (int i = 0; i < m_size; i++)
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
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_pAdjMatrix[i] = new int[this->m_size];
        for (int j = 0; j < this->m_size; j++)
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
    //return m_vertexList.Len();
}

template <class T>
bool AdjMatrixGraph<T>::GetVertexData(int i, T& value)
{
    return m_vertexList.Get(i, value);
}

template <class T>
void AdjMatrixGraph<T>::InsertVertex(T vertex)
{
    m_vertexList.Insert(vertex);
    this->m_vertexCount++;

    if (this->m_vertexCount > m_size)
    {
        int** tmp = m_pAdjMatrix;
        m_pAdjMatrix = new int*[m_size * 2];

        for (int i = 0; i < m_size; i++)
        {
            m_pAdjMatrix[i] = new int[m_size * 2];
            for (int j = 0; j < m_size; j++)
            {
                m_pAdjMatrix[i][j] = tmp[i][j];
            }
            for (int j = m_size; i < m_size * 2; j++)
            {
                m_pAdjMatrix[i][j] = MAX_WEIGHT;
            }
            
        }
        
        for (int i = m_size; i < m_size * 2; i++)
        {
            m_pAdjMatrix[i] = new int[m_size * 2];
            for (int j = 0; i < m_size * 2; j++)
            {
                m_pAdjMatrix[i][j] = (i == j) ? 0 : MAX_WEIGHT;
            }
            
        }
        m_size *= 2;
    }
    
}

template <class T>
bool AdjMatrixGraph<T>::InsertEdge(int i, int j, int weight)
{
    if (0 <= i && i < this->m_vertexCount && 0 <= j && j < this->m_vertexCount && 
        i != j && this->m_pAdjMatrix[i][j] == MAX_WEIGHT)
    {
        this->m_pAdjMatrix[i][j] = weight;
        return true;
    }
    
    return false;
}

template <class T>
bool AdjMatrixGraph<T>::InsertEdge(EdgeT edge)
{
    return this->InsertEdge(edge.m_start, edge.m_dest, edge.m_weight);
}

template <class T>
bool AdjMatrixGraph<T>::RemoveEdge(int i, int j)
{
    if (0 <= i && i < this->m_vertexCount && 0 <= j && j < this->m_vertexCount && 
        i != j && this->m_pAdjMatrix[i][j] != MAX_WEIGHT)
    {
        this->m_pAdjMatrix[i][j] = MAX_WEIGHT;
        return true;
    }
    
    return false;
}

template <class T>
bool AdjMatrixGraph<T>::RemoveVertex(int pos, T& old)
{
    if (0 <= pos && pos < this->m_vertexCount && this->m_vertexList.Remove(pos, old))
    {
        // 列前移1列
        for (int i = 0; i < this->m_vertexCount; i++)
        {
            for (int j = pos; j < this->m_vertexCount - 1; j++)
            {
                m_pAdjMatrix[i][j] = m_pAdjMatrix[i][j+1];
            }
        }
        
        // 行上移1行
        for (int i = pos; i < this->m_vertexCount - 1; i++)
        {
            for (int j = 0; j < this->m_vertexCount; j++)
            {
                m_pAdjMatrix[i][j] = m_pAdjMatrix[i + 1][j];
            }
            
        }
        
        this->m_vertexCount--;
        return true;
    }
    
    return false;
}