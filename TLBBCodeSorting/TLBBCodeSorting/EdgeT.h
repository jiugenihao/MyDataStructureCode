/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�EdgeT.h
// ������������Ȩֵ�ı߽ṹ����
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

template <class T>
class EdgeT
{
public:
    int m_start;        // ������
    int m_dest;         // �յ����
    int m_weight;       // �ߵ�Ȩֵ

public:
    EdgeT()
    {
        m_start  = 0;
        m_dest   = 0;
        m_weight = 0;
    }
    EdgeT(int start, int dest, int weight)
    {
        m_start  = start;
        m_dest   = dest;
        m_weight = weight;
    }

    ~EdgeT() {}

public:
    friend ostream& operator << (ostream& out, EdgeT& edge)
    {
        out << "output edges: ";
        out << "(" << edge.m_start << "," << edge.m_dest << "," << edge.m_weight << ")" << endl;

        return out;
    }
};

