/////////////////////////////////////////////////////////////////////////////////
// 文件名称：MyTreeT.h
// 功能描述：树的存储结构表示法
//          1.双亲表示法---找双亲很容易，找孩子不容易
//          2.孩子表示法---找孩子很容易，找双亲不容易
//          3.孩子兄弟表示法---二叉链表表示
//          将1和2结合使用，就访问双亲和孩子都很方便了
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "BaseDefine.h"

#define MAX_TREE_SIZE 100

// 树的双亲顺序表存储表示法
template <class T>
class PTNode
{
public:
    T   m_Data;
    int m_nParent;
};

template <class T>
class MyPTreeT
{
private:
    PTNode  m_PTNodes[MAX_TREE_SIZE];
    int     m_nRootPos;                 // 根结点位置
    int     m_nCount;                   // 结点数
public:
    MyPTreeT(/* args */);
    ~MyPTreeT();
};


// 树的孩子链表存储表示法
struct CTNode
{
    CTNode* m_pNext;
    int     m_nChild;
};

template <class T>
struct CTBox
{
    T       m_Data;
    CTNode* m_pFirstChild;
};

template <class T>
class MyCTreeT
{
private:
    CTBox   m_CTBoxs[MAX_TREE_SIZE];
    int     m_nRootPos;                 // 根结点位置
    int     m_nCount;                   // 结点数
public:
    MyCTreeT(/* args */);
    ~MyCTreeT();
};

// 树的二叉链表(孩子-兄弟)存储表示法
template <class T>
class CSNode
{
private:
    T       m_Data;
    CSNode* m_pFirstChild, m_pNextSibling;
public:
    CSNode(/* args */);
    ~CSNode();
};


