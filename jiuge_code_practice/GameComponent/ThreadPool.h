/*
**功能描述：线程封装类
**文件说明：
**作    者：jiuge
**创建时间：2019-11-29
**修    改：
*/

#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "MyThread.h"

#define MAX_THREAD_NUM 256
class ThreadPool
{
public:
	ThreadPool(BOOL needDel = TRUE);
	~ThreadPool();

	// start thread
	BOOL		StartPoolThread();

	// stop thread
	BOOL		StopPoolThread();

	// add thread
	BOOL		AddPoolThread(MyThread* thread);

	// del thread
	BOOL		DelPoolThread(ThreadID tid);

	// get thread by tid
	MyThread*	GetPoolThread(ThreadID tid);

	// get thread by index
	MyThread*	GetPoolThreadByIndex(UINT index);

	// get thread count
	UINT		GetThreadCount();

private:
	MyThread*	m_pThread[MAX_THREAD_NUM];	// 保存的线程
	INT			m_nCount;					// 线程数量
	BOOL		m_NeedDel;					// 是否需要释放
};

#endif

