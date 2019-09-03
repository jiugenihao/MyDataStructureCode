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

#include "CreateBinaryTree.h"
#include <time.h>

int main()
{
	int elements[] = { 111,222,333,444,777,888,999 };
	int elements2[] = { 1,2,3,4,5,6,7,8,9 };
	char levelList[] = "ABCDEFGHIJ";
	int old = 0;
	int sortList[] = {54, 18, 66, 87, 36, 12, 54, 81, 15, 76, 57, 6, 40, 99, 85, 99};
	int weight[] = {5, 29, 7, 8, 14, 23, 3, 11};

	MySqListT<char> char_sqList(10);
	char_sqList.Insert('A');
	char_sqList.Insert('B');
	char_sqList.Insert('C');
	cout << char_sqList;
	char_sqList.Insert('D');
	char_sqList.Insert('E');
	cout << char_sqList;

	char vertices[] = "ABCDE";
	char oldChar = ' ';

	cout << "/*--------------- AdjListGraph ---------------*/" << endl;
	EdgeT edge0[] = {{0,1,5}, {0,3,2}, {1,0,6}, {1,2,7}, {2,4,3}, {3,2,8}, {3,4,9}};
	AdjListGraph<char> adjListGraph(vertices, strlen(vertices), edge0, sizeof(edge0) / sizeof(EdgeT));
	cout << "带权有向图：" << endl;
	cout << adjListGraph;
	if (adjListGraph.RemoveVertex(2, oldChar))
	{
		cout << "删除顶点 " << oldChar << endl;
	}
	cout << "删除边(2, 3) ," << adjListGraph.RemoveEdge(2, 3) << endl;
	cout << adjListGraph << endl;

	cout << "/*--------------- AdjMatrixGraph ---------------*/" << endl;
	
	EdgeT edges[] = {{0,1,5}, {0,3,2}, {1,0,5}, {1,2,7}, {1,3,6}, {2,1,7}, {2,3,8}, {2,4,3},
					{3,0,2}, {3,1,6}, {3,2,8}, {3,4,9}, {4,2,3}, {4,3,9}};
	AdjMatrixGraph<char> adjGraph(vertices, strlen(vertices), edges, sizeof(edges) / sizeof(EdgeT));
	cout << adjGraph;
	adjGraph.InsertVertex('F');
	cout << "插入顶点F，插入边(A,F,20)?" << adjGraph.InsertEdge(0, 5, 20) << endl;
	
	cout << adjGraph;
	
	if (adjGraph.RemoveVertex(2, oldChar))
	{
		cout << "删除顶点 " << oldChar << endl;
	}
	cout << "删除边(2,3)," << (adjGraph.RemoveEdge(2, 3) && adjGraph.RemoveEdge(3, 2)) << endl;
	cout << adjGraph;

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

	cout << "/*--------------- MyHaffmanTree ---------------*/" << endl;
	MyHuffmanTree haffmanTree(weight, sizeof(weight) / sizeof(int));
	haffmanTree.Print();

	/*--------------- MyBinaryTreeT ---------------*/
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
	BinaryNode<char> *find = char_bittree2.Search(find_c);
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

	/*--------------- MyLinkQueueT ---------------*/
	cout << "/*--------------- MyLinkQueueT ---------------*/" << endl;
	MyLinkQueueT<int> int_link_queue;
	int_link_queue.EnQueue(1212);
	int_link_queue.EnQueue(2323);
	int_link_queue.EnQueue(3434);
	int_link_queue.EnQueue(4545);
	cout << int_link_queue;
	old = int_link_queue.DeQueue();
	cout << int_link_queue;
	old = int_link_queue.DeQueue();
	cout << int_link_queue;
	int_link_queue.EnQueue(99999);
	int_link_queue.EnQueue(85344);
	cout << int_link_queue;
	int_link_queue.Clear();
	cout << int_link_queue;

	/*--------------- MySqQueueT ---------------*/
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
	/*--------------- MyDLinkedListT ---------------*/
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
	int_dlist.Remove(1, old);
	cout << "remove[1]=" << old << endl;
	cout << int_dlist;

	MyDLinkedListT<int>* int_dlist2 = new MyDLinkedListT<int>();
	for (size_t i = 0; i < sizeof(elements2)/sizeof(elements[0]); i++)
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
	/*--------------- MyLinkStackT ---------------*/
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
	
	/*--------------- MySqStackT ---------------*/
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

	/*--------------- MySinglyLinkedListT ---------------*/
	cout << "/*--------------- MySinglyLinkedListT ---------------*/" << endl;
	MySinglyLinkedListT<int>* singly_list = new MySinglyLinkedListT<int>(elements, sizeof(elements)/sizeof(int));
	//singly_list->Visit();
	cout << *singly_list;

	//int old = 0;
	singly_list->Get(0, old);
	cout << "old=" << old << endl;
	LinkListNode<int>* singly_node = singly_list->GetNode(3);
	cout << singly_node->m_Data << endl;

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
	/*--------------- MySqList ---------------*/
	//MySqList<char> str(4);
	/*MySqList<int> mySqList(10);
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
	cout << old << endl;*/

	// enum111
	/*cout << x << endl;
	cout << x << endl;
	cout << x << endl;*/
	// list test
	/*MyList g_MyList(4);
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
	g_MyList.Print();*/

	// queue test

	/*MyQueue g_MyQueue(10);
	float data2[]{ 1.0, 2.0, 3.0 };
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
	cout << "size=" << g_MyQueue.GetSize() << endl;*/

	// stack test
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
