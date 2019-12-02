/*
**�����������̷߳�װ��
**�ļ�˵����
**��    �ߣ�jiuge
**����ʱ�䣺2019-11-29
**��    �ģ�
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
	MyThread*	m_pThread[MAX_THREAD_NUM];	// ������߳�
	INT			m_nCount;					// �߳�����
	BOOL		m_NeedDel;					// �Ƿ���Ҫ�ͷ�
};

#endif

