/////////////////////////////////////////////////////////////////////////////////
// 文件名称：EdgeT.h
// 功能描述：带权值的边结构声明
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

template <class T>
class EdgeT
{
public:
    int m_start;        // 起点序号
    int m_dest;         // 终点序号
    int m_weight;       // 边的权值

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

