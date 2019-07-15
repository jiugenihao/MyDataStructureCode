// TLBBCodeSorting.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "BaseDefine.h"
#include "MyQueue.h"
#include "MyStack.h"
#include "MyList.h"
#include "MySqList.h"
#include "MySqList.cpp"

enum enum111 {
	x1,
	x2,
	x3 = 10,
	x4,
	x5,
} x;

int main()
{
	//MySqList<char> str(4);
	MySqList<int> mySqList(10);
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

	cout << x << endl;
	cout << x << endl;
	cout << x << endl;
	// list test
	MyList g_MyList(4);
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
	// queue test
	int elements[] = { 111,222,333,444,777,888,999 };

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
	MyStack stack(6);
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
