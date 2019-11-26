/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�MyTreeT.h
// �������������Ĵ洢�ṹ��ʾ��
//          1.˫�ױ�ʾ��---��˫�׺����ף��Һ��Ӳ�����
//          2.���ӱ�ʾ��---�Һ��Ӻ����ף���˫�ײ�����
//          3.�����ֵܱ�ʾ��---���������ʾ
//          ��1��2���ʹ�ã��ͷ���˫�׺ͺ��Ӷ��ܷ�����
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "BaseDefine.h"

#define MAX_TREE_SIZE 100

// ����˫��˳���洢��ʾ��
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
    int     m_nRootPos;                 // �����λ��
    int     m_nCount;                   // �����
public:
    MyPTreeT(/* args */);
    ~MyPTreeT();
};


// ���ĺ�������洢��ʾ��
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
    int     m_nRootPos;                 // �����λ��
    int     m_nCount;                   // �����
public:
    MyCTreeT(/* args */);
    ~MyCTreeT();
};

// ���Ķ�������(����-�ֵ�)�洢��ʾ��
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


