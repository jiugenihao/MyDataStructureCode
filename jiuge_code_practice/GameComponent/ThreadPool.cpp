#include "ThreadPool.h"
#include "CommonDefine.h"

ThreadPool::ThreadPool(BOOL needDel)
{
	for (UINT i = 0; i < MAX_THREAD_NUM; ++i)
	{
		m_pThread[i] = nullptr;
	}
	m_nCount = 0;
	m_NeedDel = needDel;
}

ThreadPool::~ThreadPool()
{
	m_nCount = 0;
	for (UINT i = 0; i < MAX_THREAD_NUM; ++i)
	{
		if (m_NeedDel)
		{
			SAFE_DELETE(m_pThread[i]);
		}
		else
		{
			m_pThread[i] = nullptr;
		}
	}
}

BOOL ThreadPool::StartPoolThread()
{
	if (m_nCount == 0)
	{
		return FALSE;
	}

	for (UINT i = 0; i < MAX_THREAD_NUM; ++i)
	{
		if (m_pThread[i])
		{
			if (!m_pThread[i]->Start())
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

BOOL ThreadPool::StopPoolThread()
{
	for (UINT i = 0; i < MAX_THREAD_NUM; ++i)
	{
		if (m_pThread[i])
		{
			m_pThread[i]->Exit();
		}
	}
	return TRUE;
}

BOOL ThreadPool::AddPoolThread(MyThread* thread)
{
	return 0;
}

BOOL ThreadPool::DelPoolThread(ThreadID tid)
{
	return 0;
}

MyThread* ThreadPool::GetPoolThread(ThreadID tid)
{
	for (UINT i = 0; i < MAX_THREAD_NUM; ++i)
	{
		if (nullptr != m_pThread[i] && tid == m_pThread[i]->GetTID())
		{
			return m_pThread[i];
		}
	}
	return nullptr;
}

MyThread* ThreadPool::GetPoolThreadByIndex(UINT index)
{
	if (index >= MAX_THREAD_NUM)
	{
		return nullptr;
	}
	return m_pThread[index];
}

UINT ThreadPool::GetThreadCount()
{
	return m_nCount;
}
