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

#include <time.h>

enum enum111 {
	x1,
	x2,
	x3 = 10,
	x4,
	x5,
} x;

int main()
{
	/*char FileAllPath[100] = { 0 };
	time_t _time;
	time(&_time);
	struct tm _tm;
	localtime_s(&_tm, &_time);

	struct tm *ptm = &_tm;
	snprintf(FileAllPath, sizeof(FileAllPath) - 1, "%s%s.%d-%02d-%02d.%02d%02d%02d.svr_%d.log",
		"hello", "-world", 1900 + ptm->tm_year, 1 + ptm->tm_mon, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, 111);

	cout << FileAllPath << endl;
	int len = strnlen_s(FileAllPath, 100);
	cout << "len=" << len << "   " << FileAllPath[len - 1] << endl;
	FileAllPath[len] = '\0';
	len = strnlen_s(FileAllPath, 100);
	cout << "len=" << len << "   " << FileAllPath[len - 1] << endl;*/
	int elements[] = { 111,222,333,444,777,888,999 };
	int elements2[] = { 1,2,3,4,5,6,7,8,9 };

	int old = 0;
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
