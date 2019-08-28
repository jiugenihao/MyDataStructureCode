/////////////////////////////////////////////////////////////////////////////////
//文件名称：MyHuffmanTree.h
//功能描述：哈夫曼树，变长编码用于无损压缩
//   
/////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "BaseDefine.h"

class TriNode
{
public:
	TriNode()
	{
		m_nParent = m_nLeft = m_nRight = -1;
	}
	~TriNode()
	{

	}

public:
	int	m_nWeight;
	int m_nParent;
	int m_nLeft;
	int m_nRight;
};

class MyHuffmanTree
{
public:
	MyHuffmanTree(int weightList[], int n)
	{
		CreateHaffmanTree(weightList, n);
		GetHaffmanCode();
	}
	~MyHuffmanTree()
	{
		SAFE_DELETE_ARRAY(m_pTriNode);
		SAFE_DELETE_ARRAY(m_pHuffCode);
	}

	void CreateHaffmanTree(int weightList[], int n)
	{
		if (n <= 1)
		{
			return;
		}
		
		m_nLeafNum = n;
		m_pTriNode = new TriNode[2 * n - 1];
		

		for (int i = 0; i < n; ++i)
		{
			m_pTriNode[i].m_nWeight = weightList[i];
			m_pTriNode[i].m_nParent = -1;
			m_pTriNode[i].m_nLeft	= -1;
			m_pTriNode[i].m_nRight	= -1;
		}

		// 因为每次取两个数，所以i < n - 1
		for (int i = 0; i < n-1; i++)
		{
			// 每次从列表取两个权值最小的，并且没有双亲
			int min1, min2, pos1, pos2;
			min1 = min2 = MAX_WEIGHT;
			pos1 = pos2 = -1;

			for (int j = 0; j < n + i; ++j)
			{
				if (m_pTriNode[j].m_nWeight < min1 && m_pTriNode[j].m_nParent == -1)
				{
					min2 = min1;
					pos2 = pos1;
					min1 = m_pTriNode[j].m_nWeight;
					pos1 = j;
				}
				else if (m_pTriNode[j].m_nWeight < min2 && m_pTriNode[j].m_nParent == -1)
				{
					min2 = m_pTriNode[j].m_nWeight;
					pos2 = j;
				}
				
			}

			m_pTriNode[pos1].m_nParent 	= n + i;
			m_pTriNode[pos2].m_nParent 	= n + i;
			m_pTriNode[n + i].m_nWeight = min1 + min2;
			m_pTriNode[n + i].m_nParent = -1;
			m_pTriNode[n + i].m_nLeft 	= pos1;
			m_pTriNode[n + i].m_nRight 	= pos2;
		}
		
		
	}

	void GetHaffmanCode()
	{
		int n = m_nLeafNum;
		m_pHuffCode = new char*[m_nLeafNum];

		for(int i = 0; i < n; ++i)
		{
			char* code = new char[n];
			code[n - 1] = '\0';
			int start = n - 1;
			int child = i;
			int parent = m_pTriNode[child].m_nParent;
			while (parent != -1)
			{
				start--;
				if (child == m_pTriNode[parent].m_nLeft)
				{
					code[start] = '0';
				}
				else
				{
					code[start] = '1';
				}
				child = parent;
				parent = m_pTriNode[child].m_nParent;
			}
			m_pHuffCode[i] = code + start;
		}
	}

	void Print()
	{
		cout << "哈夫曼树的结点数组：" << endl;
		for (int i = 0; i < m_nLeafNum * 2 - 1; ++i)
		{
			cout << "Node[" << setw(2) << i << "]: " << setw(4) << m_pTriNode[i].m_nWeight << " " << setw(4) << m_pTriNode[i].m_nParent << " " << setw(4) << m_pTriNode[i].m_nLeft << " " << setw(4) << m_pTriNode[i].m_nRight << endl;
		}
		cout << endl;

		cout << "哈夫曼编码：" << endl;
		for (int i = 0; i < m_nLeafNum; ++i)
		{
			cout << "Node[" << setw(2) << i << "]: " << setw(4) << m_pTriNode[i].m_nWeight << "  huffcode:" << m_pHuffCode[i] << endl;
		}
		cout << endl;

	}

private:

	TriNode* m_pTriNode;
	char**	 m_pHuffCode;
	int		 m_nLeafNum;
};

