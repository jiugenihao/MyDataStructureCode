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

template<class T>
int AdjMatrixGraph<T>::GetFirstNeighbor(int v)
{
	// 返回v的第一个邻接点序号，如果不存在返回-1
	return GetNextNeighbor(v, -1);
}

template<class T>
int AdjMatrixGraph<T>::GetNextNeighbor(int v, int w)
{
	if (0 <= v && v < m_vertexCount && -1 <= w && w < m_vertexCount && v != w)
	{
		for (int i = w+1; i < m_vertexCount; i++)
		{
			// w=-1时，j从0开始寻找下一个邻接点
			if (m_pAdjMatrix[v][i] > 0 && m_pAdjMatrix[v][i] < MAX_WEIGHT)
			{
				return i;
			}
		}
	}
	return -1;
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

// n个顶点，n-1条边
template<class T>
void AdjMatrixGraph<T>::MinSpanTree_Prim(EdgeT* mst)
{
	int n = this->m_vertexCount, i, j;

	// 初始化mst数组，保存从v0出发的边，从顶点v0出发构造最小生成树
	for (i = 0; i < n - 1; ++i)
	{
		EdgeT edge(0, i + 1, this->m_pAdjMatrix[0][i + 1]);
		mst[i] = edge;
	}

	// 选出n-1条边
	for (i = 0; i < n - 1; ++i)
	{
		int minWeight = MAX_WEIGHT;
		int min = i;

		// 寻找权值最小的边的顶点
		for (j = 0; j < n - 1; ++j)
		{
			if (mst[j].m_weight < minWeight)
			{
				minWeight = mst[j].m_weight;
				min = j;
			}
		}

		EdgeT tmp = mst[i];
		mst[i] = mst[min];
		mst[min] = tmp;

		// 刚刚并入U的顶点
		int u = mst[i].m_dest;
		// 调整mst[i+1]及其之后元素为权值最小的边
		for (j = i + 1; j < n - 1; ++j)
		{
			int v = mst[j].m_dest;
			if (this->m_pAdjMatrix[u][v] < mst[j].m_weight)
			{
				mst[j].m_weight = this->m_pAdjMatrix[u][v];
				mst[j].m_start = u;
			}
		}
	}

	cout << endl;
	cout << "最小生成树的边集合：";
	int minCost = 0;
	for (i = 0; i < n - 1; ++i)
	{
		cout << mst[i].m_weight << " ";
		minCost += mst[i].m_weight;
	}
	cout << endl;
	cout << "最小代价为：" << minCost << endl;
}

template<class T>
void AdjMatrixGraph<T>::MinSpanTree_Kruskal()
{
}
