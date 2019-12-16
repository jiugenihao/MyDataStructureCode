// TLBBCodeSorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "BaseDefine.h"
#include "MyIntQueue.h"
#include "MyIntStack.h"
#include "MyIntList.h"

#include "MySqListT.cpp"
#include "MySqStackT.cpp"
#include "MySqQueueT.cpp"

#include "MyLinkedListT.cpp"
#include "MyDLinkedListT.cpp"
#include "MyLinkStackT.cpp"
#include "MyLinkQueueT.cpp"
#include "MyBinaryTreeT.cpp"
#include "MyHuffmanTree.h"
#include "MyBinarySortTree.h"
#include "MyBinarySortTree.cpp"
#include "AdjMatrixGraph.h"
#include "AdjMatrixGraph.cpp"
#include "AdjListGraph.h"
#include "AdjListGraph.cpp"

#include "StringSplit.h"

#include "CreateBinaryTree.h"
#include "RemoveOpe.h"
#include <time.h>
#include "StringConvert.h"
#include "SortUtility.h"

using namespace MyString;

// global data
int elements[] = { 111,222,333,444,777,888,999 };
int elements2[] = { 1,2,3,4,5,6,7,8,9 };

char levelList[] = "ABCDEFGHIJ";

int sortList[] = { 54, 18, 66, 87, 36, 12, 54, 81, 15, 76, 57, 6, 40, 99, 85, 99 };
int weight[] = { 5, 29, 7, 8, 14, 23, 3, 11 };

char vertices[] = "ABCDE";
EdgeT directedEdges[] = { {0,1,5}, {0,3,2}, {1,0,6}, {1,2,7}, {2,4,3}, {3,2,8}, {3,4,9} };
EdgeT undirectedEdges[] = { {0,1,5}, {0,3,2}, {1,0,5}, {1,2,7}, {1,3,6}, {2,1,7}, {2,3,8}, {2,4,3},
				{3,0,2}, {3,1,6}, {3,2,8}, {3,4,9}, {4,2,3}, {4,3,9} };

// MyIntStack
void TestMyIntStack()
{
	MyIntStack stack(6);
	for (auto value : elements)
	{
		if (!stack.Push(value))
		{
			cout << "My stack is full ..." << endl;
		}
	}

	stack.Print();
	cout << "pop elements :";
	cout << stack.Pop() << "-";
	cout << stack.Pop() << "-";
	cout << endl;
	stack.Print();
	stack.Push(1234);
	stack.Push(2345);
	stack.Print();
}

// MyIntQueue
void TestMyIntQueue()
{
	MyIntQueue g_MyQueue(10);
	for (auto value : elements)
	{
		if (!g_MyQueue.PushBack(value))
		{
			cout << "My queue is full ..." << endl;
		}
	}

	g_MyQueue.Print();
	cout << "size=" << g_MyQueue.GetSize() << endl;
	cout << "pop list is:";
	cout << g_MyQueue.PopFront() << "-";
	cout << g_MyQueue.PopFront() << "-";
	cout << g_MyQueue.PopFront() << "-";
	cout << g_MyQueue.PopFront() << endl;

	g_MyQueue.Print();
	cout << "size=" << g_MyQueue.GetSize() << endl;
	g_MyQueue.PushBack(9999);
	g_MyQueue.Print();
	cout << "size=" << g_MyQueue.GetSize() << endl;
}

// MyIntList
void TestMyIntList()
{
	MyIntList g_MyList(4);
	bool ret;
	ret = g_MyList.Insert(0, 111);
	ret = g_MyList.Insert(1, 222);
	ret = g_MyList.Insert(2, 333);
	ret = g_MyList.Insert(2, 444);
	ret = g_MyList.Insert(2, 555);

	g_MyList.Print();
	cout << "g_MyList[2]=" << g_MyList[2] << endl;

	int oldElem = 0;
	g_MyList.Remove(1, oldElem);
	g_MyList.Print();
}

// test string
void TestString()
{
	cout << MyString::atoi("-1234567") << endl;
	cout << MyString::atoi("-001200") << endl;
	cout << MyString::atoi("abcd3456") << endl;
	//cout << atoi("abcd3456") << endl;
	char int2_str[20] = { 0 };
	char int8_str[20] = { 0 };
	char int10_str[20] = { 0 };
	char int16_str[20] = { 0 };
	MyString::itoa(100, int2_str, 2);
	MyString::itoa(100, int8_str, 8);
	MyString::itoa(100, int10_str, 10);
	MyString::itoa(100, int16_str, 16);
	//cout << itoa(100654, int_str, 10) << endl;
	cout << int2_str << endl;
	cout << int8_str << endl;
	cout << int10_str << endl;
	cout << int16_str << endl;
	for (int i = 0; i < strlen(int2_str); i++)
	{
		cout << "int2_str[" << i << "] = " << int2_str[i] << endl;
	}
}

void TestStringSplit()
{
	cout << "/*--------------- String Start---------------*/" << endl;
	string test_split_str_i = "1|2|3|4|5";
	string test_split_str_bi = "11111111111111111111|222222222222222222222|33333333333|44444444444|555555555555555";
	string test_split_str_f = "11.1|2.22|333.0|44.3|9.2";
	string test_split_str_s = "abcd|efg|hijklmn|opq|rst";

	vector<string> split_vec_i;
	MyStrTok(test_split_str_f, split_vec_i, "|");
	for (auto item : split_vec_i)
	{
		float value = stof(item, nullptr);
		//int64_t value = stold(item, nullptr);
		cout << value << " ";
	}
	cout << endl;

	StringSplit split_i(test_split_str_i.c_str(), _STRING_DELIMITER);
	StringSplit split_bi(test_split_str_bi.c_str(), _STRING_DELIMITER);
	StringSplit split_f(test_split_str_f.c_str(), _STRING_DELIMITER);
	StringSplit split_s(test_split_str_s.c_str(), _STRING_DELIMITER);

	int splitCti = split_i.ConvertToInt();
	int splitCtbi = split_bi.ConvertToBigInt();
	int splitCtf = split_f.ConvertToFloat();
	int splitCts = split_s.ConvertToString();


	for (int i = 0; i < splitCti; ++i)
	{
		cout << "split_i[" << i << "] = " << split_i.GetInt(i) << endl;
		cout << "split_bi[" << i << "] = " << split_bi.GetBigInt(i) << endl;
		cout << "split_f[" << i << "] = " << split_f.GetFloat(i) << endl;
		cout << "split_s[" << i << "] = " << split_s.GetString(i) << endl;
	}
}

void TestQuestion()
{
	cout << "/*--------------- Question Start---------------*/" << endl;
	int data_lw[] = { 2, 3, 4, 2, 5, 7, 2, 2, 2, 8, 2 };
	int data_me[] = { 2, 3, 4, 2, 5, 7, 2, 2, 2, 8, 2 };
	int data_zq[] = { 2, 3, 4, 2, 5, 7, 2, 2, 2, 8, 2 };
	int data_len = sizeof(data_lw) / sizeof(int);
	cout << "lw:" << Question::RemoveAll_lw(data_lw, 11, 2) << endl;
	cout << "me:" << Question::RemoveAll_me(data_me, data_len, 2) << endl;
	cout << "zq:" << Question::RemoveAll_zq(data_zq, 11, 2) << endl;

	cout << "/*--------------- Question End  ---------------*/" << endl;

	/*MyIntList d;
	typedef void(*Fun)(void);

	int* AAA = (int*)(&d);
	int* BBB = (int*) * (AAA);

	Fun fun1 = (Fun) * (BBB);

	Fun fun2 = (Fun) * ((int*) * ((int*)(&d)));
	Fun fun3 = (Fun) * ((int**)((int*)(&d)));*/
}

// MySqListT<T>
void TestSqListT()
{
	MySqListT<char> char_sqList(10);
	char_sqList.Insert('A');
	char_sqList.Insert('B');
	char_sqList.Insert('C');
	cout << char_sqList;
	char_sqList.Insert('D');
	char_sqList.Insert('E');
	cout << char_sqList;

	/*--------------- MySqList ---------------*/
	MySqListT<int> mySqList(10);
	cout << "len = " << mySqList.Len() << endl;
	cout << "size = " << mySqList.Capacity() << endl;
	cout << sizeof(mySqList) << endl;
	mySqList.Insert(111);
	mySqList.Insert(222);
	mySqList.Insert(333);
	mySqList.Insert(444);
	cout << mySqList;
	cout << "len = " << mySqList.Len() << endl;
	cout << "size = " << mySqList.Capacity() << endl;
	int old = 0;
	mySqList.Remove(2, old);
	cout << old << endl;
}

// MySqStackT<T>
void TestSqStackT()
{
	cout << "/*--------------- MySqStackT ---------------*/" << endl;
	MySqStackT<char> char_stack(5);
	char_stack.Push('q');
	char_stack.Push('w');
	char_stack.Push('e');
	char_stack.Push('r');
	char_stack.Print();

	char c0 = char_stack.Pop();
	char c1 = char_stack.GetTop();

	cout << "pop:" << c0 << endl;
	cout << "top:" << c1 << endl;
	char_stack.Push('+');
	char_stack.Push('-');
	cout << "top:" << char_stack.GetTop() << endl;
	cout << "pop:" << char_stack.Pop() << endl;
	cout << "top:" << char_stack.GetTop() << endl;
	char_stack.Print();
	char_stack.Clear();
	char_stack.Print();
}

// MySqQueueT<T>
void TestSqQueueT()
{
	cout << "/*--------------- MySqQueueT ---------------*/" << endl;
	MySqQueueT<int> int_sq_queue(3);
	int_sq_queue.EnQueue(100);
	int_sq_queue.EnQueue(35);
	cout << "size=" << int_sq_queue.Size() << endl;
	cout << int_sq_queue;

	for (size_t i = 0; i < 5; ++i)
	{
		int_sq_queue.EnQueue(elements[i]);
	}
	cout << "size=" << int_sq_queue.Size() << endl;
	cout << int_sq_queue;

	cout << "remove:" << int_sq_queue.DeQueue() << endl;
	cout << "remove:" << int_sq_queue.DeQueue() << endl;
	cout << "remove:" << int_sq_queue.DeQueue() << endl;
	cout << "size=" << int_sq_queue.Size() << endl;
	cout << int_sq_queue;

	int_sq_queue.EnQueue(12345);
	int_sq_queue.EnQueue(54321);
	int_sq_queue.EnQueue(34343);
	int_sq_queue.EnQueue(123321);
	cout << "size=" << int_sq_queue.Size() << endl;
	cout << int_sq_queue;
}

// MySinglyLinkedListT<T>
void TestSinglyLinkedListT()
{
	cout << "/*--------------- MySinglyLinkedListT ---------------*/" << endl;
	MySinglyLinkedListT<int>* singly_list = new MySinglyLinkedListT<int>(elements, sizeof(elements) / sizeof(int));
	cout << *singly_list;

	LinkListNode<int>* pReverseNode = singly_list->Reverse();
	cout << *singly_list;

	LinkListNode<int>* pReverseNode2 = singly_list->ReverseRecur(singly_list->GetRoot());
	singly_list->SetRoot(pReverseNode2);
	cout << *singly_list;

	int old = 0;
	singly_list->Get(0, old);
	cout << "old=" << old << endl;
	LinkListNode<int>* singly_node = singly_list->GetNode(3);
	cout << "Node 3:" << singly_node->m_Data << endl;
	singly_node = singly_list->FindMid();
	cout << "Node Mid:" << singly_node->m_Data << endl;

	if (singly_list->Remove(4, old))
	{
		cout << "remove 3th:" << old << endl;
	}
	else
	{
		cout << "remove failed..." << endl;
	}
	cout << *singly_list;

	bool bRet = singly_list->Remove(10, old);

	MySinglyLinkedListT<int> singly_list2;
	for (size_t i = 0; i < 5; ++i)
	{
		singly_list2.Insert(i, elements2[i]);
	}
	cout << singly_list2;
	singly_list->Concat(singly_list2);
	cout << *singly_list;
	cout << singly_list2;
}

// MyLinkStackT<T>
void TestLinkStackT()
{
	cout << "/*--------------- MyLinkStackT ---------------*/" << endl;
	MyLinkStackT<int> int_stack;
	for (auto value : elements)
	{
		int_stack.Push(value);
	}
	int_stack.Print();
	cout << "top:" << int_stack.GetTop() << endl;
	cout << "pop:" << int_stack.Pop() << endl;
	cout << "top:" << int_stack.GetTop() << endl;
	cout << "pop:" << int_stack.Pop() << endl;
	cout << "top:" << int_stack.GetTop() << endl;
	cout << "pop:" << int_stack.Pop() << endl;
	cout << "top:" << int_stack.GetTop() << endl;

	int_stack.Print();
	int_stack.Clear();
	int_stack.Print();
}

// MyLinkQueueT<T>
void TestLinkQueueT()
{
	cout << "/*--------------- MyLinkQueueT ---------------*/" << endl;
	MyLinkQueueT<int> int_link_queue;
	int_link_queue.EnQueue(1212);
	int_link_queue.EnQueue(2323);
	int_link_queue.EnQueue(3434);
	int_link_queue.EnQueue(4545);
	cout << int_link_queue;

	int old = 0;
	old = int_link_queue.DeQueue();
	cout << int_link_queue;
	old = int_link_queue.DeQueue();
	cout << int_link_queue;
	int_link_queue.EnQueue(99999);
	int_link_queue.EnQueue(85344);
	cout << int_link_queue;
	int_link_queue.Clear();
	cout << int_link_queue;
}

// MyDLinkedListT<T>
void TestDLinkedListT()
{
	cout << "/*--------------- MyDLinkedListT ---------------*/" << endl;
	MyDLinkedListT<int> int_dlist;
	for (size_t i = 0; i < 5; ++i)
	{
		int_dlist.Insert(i, elements[i]);
	}
	cout << int_dlist;
	int_dlist.Insert(0, 100);
	int_dlist.Insert(3, 345);
	cout << int_dlist;
	int old = 0;
	int_dlist.Remove(1, old);
	cout << "remove[1]=" << old << endl;
	cout << int_dlist;

	MyDLinkedListT<int>* int_dlist2 = new MyDLinkedListT<int>();
	for (size_t i = 0; i < sizeof(elements2) / sizeof(elements[0]); i++)
	{
		int_dlist2->Insert(0, elements2[i]);
	}
	cout << *int_dlist2;
	int_dlist2->Remove(0, old);
	cout << "remove[1]=" << old << endl;
	int_dlist2->Remove(0, old);
	cout << "remove[1]=" << old << endl;
	int_dlist2->Remove(0, old);
	cout << "remove[1]=" << old << endl;
	int_dlist2->Remove(0, old);
	cout << "remove[1]=" << old << endl;
	cout << *int_dlist2;
	int_dlist.Concat(*int_dlist2);
	cout << int_dlist;
	cout << *int_dlist2;
}

// MyBinaryTreeT<T>
void TestBinaryTreeT()
{
	cout << "/*--------------- MyBinaryTreeT ---------------*/" << endl;
	CompleteBinaryTree<char> comBiT(levelList, strlen(levelList));
	comBiT.PreOrder();
	comBiT.InOrder();
	comBiT.PostOrder();
	comBiT.PreOrderTraverse();
	comBiT.InOrderTraverse();
	comBiT.PostOrderTraverse();
	comBiT.PrintGList();
	comBiT.LevelOrder();

	MyBinaryTreeT<char> glist_bittree;
	char gList[] = "A(B(D(^,H),E(I,^)),C(^,F(G,^)))";
	Question::CreateBiTByGList(glist_bittree, gList);
	glist_bittree.PreOrder();
	glist_bittree.InOrder();
	glist_bittree.PostOrder();
	glist_bittree.PreOrderTraverse();
	glist_bittree.InOrderTraverse();
	glist_bittree.PostOrderTraverse();
	glist_bittree.PrintGList();
	glist_bittree.LevelOrder();
	cout << setw(14) << "Count = " << glist_bittree.Count() << endl;
	cout << setw(14) << "Height = " << glist_bittree.Height() << endl;
	cout << setw(14) << "Leaf Count = " << glist_bittree.LeafCount() << endl;

	MyBinaryTreeT<char> char_bittree;
	Question::CreateCharBiT(char_bittree);
	char_bittree.PreOrder();
	char_bittree.InOrder();
	char_bittree.PostOrder();
	char_bittree.PreOrderTraverse();
	char_bittree.InOrderTraverse();
	char_bittree.PostOrderTraverse();
	char_bittree.PrintGList();
	char_bittree.LevelOrder();
	cout << setw(14) << "Count = " << char_bittree.Count() << endl;
	cout << setw(14) << "Height = " << char_bittree.Height() << endl;
	cout << setw(14) << "Leaf Count = " << char_bittree.LeafCount() << endl;
	BinaryNode<char>* binode = char_bittree.Search('D');
	BinaryNode<char>* parent = char_bittree.GetParent(binode);
	cout << "D's parent is:" << parent->m_Data << endl;

	char preList[] = { 'A','B', 'D', NULL, 'G', NULL, NULL, NULL, 'C',
		'E', NULL, NULL, 'F', 'H', NULL, NULL, NULL };
	MyBinaryTreeT<char> char_bittree2(preList, sizeof(preList));
	char_bittree2.PreOrder();
	char_bittree2.InOrder();
	char_bittree2.PostOrder();
	char_bittree2.LevelOrder();

	cout << setw(14) << "Count = " << char_bittree.Count() << endl;
	cout << setw(14) << "Height = " << char_bittree.Height() << endl;
	cout << setw(14) << "Leaf Count = " << char_bittree.LeafCount() << endl;

	char find_c = 'H';
	BinaryNode<char>* find = char_bittree2.Search(find_c);
	if (find)
	{
		BinaryNode<char>* parent = char_bittree2.GetParent(find);
		cout << find_c << "的祖先结点是：";
		while (parent)
		{
			cout << parent->m_Data << " ";
			parent = char_bittree2.GetParent(parent);
		}
		cout << endl;
	}
	else
	{
		cout << "can not find ..." << endl;
	}
	char_bittree2.GetAllAncestorNode('D');
}

// MyBinarySortTree<T>
void TestBinarySortTree()
{
	cout << "/*--------------- MyBinarySortTree ---------------*/" << endl;
	MyBinarySortTree<int> sortBiT;
	cout << setw(25) << "递归插入结点：";
	for (size_t i = 0; i < sizeof(sortList) / sizeof(int); ++i)
	{
		if (sortBiT.RecursiveInsert(sortList[i]))
		{
			cout << sortList[i] << " ";
		}
	}
	cout << endl;
	sortBiT.PreOrder();
	sortBiT.InOrder();
	cout << setw(14) << "Count = " << sortBiT.Count() << endl;
	cout << setw(14) << "Height = " << sortBiT.Height() << endl;
	cout << setw(14) << "Leaf Count = " << sortBiT.LeafCount() << endl;
	int N = 16;
	cout << "查找" << sortList[N - 1] << "," << (sortBiT.Search(sortList[N - 1]) ? "" : "不") << "成功" << endl;
	if (sortBiT.RecursiveRemove(54))
	{
		cout << "remove 54 success..." << endl;
	}
	else
	{
		cout << "remove 54 failed..." << endl;
	}
	sortBiT.PreOrder();
	sortBiT.InOrder();
	sortBiT.RecursiveInsert(54);
	sortBiT.PreOrder();
	sortBiT.InOrder();
	cout << setw(14) << "Count = " << sortBiT.Count() << endl;
	cout << setw(14) << "Height = " << sortBiT.Height() << endl;
	cout << setw(14) << "Leaf Count = " << sortBiT.LeafCount() << endl;

	MyBinarySortTree<int> sortBit2;
	cout << setw(25) << "非递归插入结点：";
	for (size_t i = 0; i < sizeof(sortList) / sizeof(int); ++i)
	{
		if (sortBit2.Insert(sortList[i]))
		{
			cout << sortList[i] << " ";
		}
	}
	cout << endl;
	sortBit2.InOrder();
	sortBit2.InOrderTraverse();
	cout << "查找" << sortList[N - 1] << "," << (sortBit2.RecursiveSearch(sortList[N - 1]) ? "" : "不") << "成功" << endl;
	cout << "查找 36," << (sortBit2.RecursiveSearch(36) ? "" : "不") << "成功" << endl;
	cout << "查找 66," << (sortBit2.RecursiveSearch(66) ? "" : "不") << "成功" << endl;

	cout << "查找" << sortList[N - 1] << "," << (sortBit2.Search(sortList[N - 1]) ? "" : "不") << "成功" << endl;
	cout << "查找 36," << (sortBit2.Search(36) ? "" : "不") << "成功" << endl;
	cout << "查找 66," << (sortBit2.Search(66) ? "" : "不") << "成功" << endl;
}

// MyHaffmanTree
void TestHaffmanTree()
{
	cout << "/*--------------- MyHaffmanTree ---------------*/" << endl;
	MyHuffmanTree haffmanTree(weight, sizeof(weight) / sizeof(int));
	haffmanTree.Print();
}

// AdjMatrixGraph
void TestAdjMatrixGraph()
{
	cout << "/*--------------- AdjMatrixGraph ---------------*/" << endl;
	EdgeT* mst_u = new EdgeT[sizeof(undirectedEdges) / sizeof(EdgeT) - 1];
	EdgeT* mst_d = new EdgeT[sizeof(directedEdges) / sizeof(EdgeT) - 1];

	AdjMatrixGraph<char> directedAMG(vertices, strlen(vertices), directedEdges, sizeof(directedEdges) / sizeof(EdgeT));
	cout << directedAMG;
	for (int i = 0; i < directedAMG.GetVertexCount(); i++)
	{
		directedAMG.DFSTraverse(i);
	}
	directedAMG.MinSpanTree_Prim(mst_d);

	AdjMatrixGraph<char> undirectedAMG(vertices, strlen(vertices), undirectedEdges, sizeof(undirectedEdges) / sizeof(EdgeT));
	cout << undirectedAMG;
	for (int i = 0; i < undirectedAMG.GetVertexCount(); i++)
	{
		undirectedAMG.DFSTraverse(i);
	}
	undirectedAMG.MinSpanTree_Prim(mst_u);

	undirectedAMG.InsertVertex('F');
	cout << "插入顶点F，插入边(A,F,20)?" << undirectedAMG.InsertEdge(0, 5, 20) << endl;

	cout << undirectedAMG;

	char oldChar = ' ';
	if (undirectedAMG.RemoveVertex(2, oldChar))
	{
		cout << "删除顶点 " << oldChar << endl;
	}
	cout << "删除边(2,3)," << (undirectedAMG.RemoveEdge(2, 3) && undirectedAMG.RemoveEdge(3, 2)) << endl;
	cout << undirectedAMG;
}

// AdjListGraph
void TestAdjListGraph()
{
	cout << "/*--------------- AdjListGraph ---------------*/" << endl;
	AdjListGraph<char> undirectedALG(vertices, strlen(vertices), undirectedEdges, sizeof(undirectedEdges) / sizeof(EdgeT));
	cout << undirectedALG;
	for (int i = 0; i < undirectedALG.GetVertexCount(); i++)
	{
		undirectedALG.DFSTraverse(i);
		undirectedALG.BFSTraverse(i);
	}

	AdjListGraph<char> directedALG(vertices, strlen(vertices), directedEdges, sizeof(directedEdges) / sizeof(EdgeT));
	cout << "带权有向图：" << endl;
	cout << directedALG;
	for (int i = 0; i < directedALG.GetVertexCount(); i++)
	{
		directedALG.DFSTraverse(i);
		directedALG.BFSTraverse(i);
	}

	char oldChar = ' ';
	if (directedALG.RemoveVertex(2, oldChar))
	{
		cout << "删除顶点 " << oldChar << endl;
	}
	cout << "删除边(2, 3) ," << directedALG.RemoveEdge(2, 3) << endl;
	cout << directedALG << endl;
}

// Sort
void TestSort()
{
	int int_arr[] = { 0,6,3,2,7,5,4,9,1,8 };
	int len = sizeof(int_arr) / sizeof(int);
	cout << "InsertSort before:" << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << int_arr[i] << " ";
	}
	cout << endl;

	//SortUtility::InsertSort(int_arr, len);
	//SortUtility::ShellSort(int_arr, len);
	//SortUtility::BubbleSort(int_arr, len);
	//SortUtility::QuickSort(int_arr, len);
	SortUtility::SelectSort(int_arr, len);

	cout << "InsertSort after:" << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << int_arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	//TestMyIntStack();				// int栈
	//TestMyIntQueue();				// int队列
	//TestMyIntList();				// int列表
	//TestQuestion();				//

	//TestSqListT();				// 数组实现的线性表
	//TestSinglyLinkedListT();		// 链表实现的线性表
	//TestSqStackT();				// 数组实现的栈
	//TestLinkStackT();				// 链表实现的栈
	//TestSqQueueT();				// 数组实现的队列
	//TestLinkQueueT();				// 链表实现的队列
	//TestDLinkedListT();			// 双向链表

	//TestBinaryTreeT();			// 二叉树
	//TestBinarySortTree();			// 二叉排序树
	//TestHaffmanTree();			// 哈夫曼树

	//TestAdjMatrixGraph();			// 邻接矩阵表示的带权图
	//TestAdjListGraph();			// 邻接表表示的带权图

	//TestString();
	//TestStringSplit();

	TestSort();
	
}

