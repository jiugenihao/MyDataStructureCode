#include "MyThread.h"

#if defined(_WIN32)
	DWORD WINAPI ThreadProcess(VOID* pParam)
	{
		MyThread* pThread = (MyThread*)pParam;
		if (nullptr == pThread)
		{
			return 0;
		}

		pThread->SetThreadStatus(ThreadStatus::STATUS_RUNNING);
		pThread->Run();
		pThread->SetThreadStatus(ThreadStatus::STATUS_EXIT);
		pThread->Exit(nullptr);

		return 0;
	}
#elif defined(__LINUX__)
	VOID* ThreadProcess(VOID* pParam)
	{
		MyThread* pThread = (MyThread*)pParam;
		if (nullptr == pThread)
		{
			return nullptr;
		}

		pThread->SetThreadStatus(ThreadStatus::STATUS_RUNNING);
		pThread->Run();
		pThread->SetThreadStatus(ThreadStatus::STATUS_EXIT);
		pThread->Exit(nullptr);

		return nullptr;
	}
#endif // _WIN32

MyThread::MyThread()
{
	m_Status	= ThreadStatus::STATUS_READY;
	m_ThreadID	= 0;
#if defined(_WIN32)
	m_hThread	= nullptr;
#endif
}

MyThread::~MyThread()
{
}

BOOL MyThread::Start()
{
	if (ThreadStatus::STATUS_READY != m_Status)
	{
		return FALSE;
	}

#if defined(_WIN32)
	m_hThread = ::CreateThread(nullptr, 0, ThreadProcess, this, 0, &m_ThreadID);
	if (INVALID_HANDLE_VALUE == m_hThread)
	{
		return FALSE;
	}
	
#elif defined(__LINUX__)
	INT nResult = pthread_create(&m_ThreadID, nullptr, ThreadProcess, this);
	if (0 != nResult)
	{
		return FALSE;
	}
#endif

	return TRUE;
}

void MyThread::Exit(VOID* retval)
{
#if defined(_WIN32)
	::CloseHandle(m_hThread);
#elif defined(__LINUX__)
	pthread_exit(retval);
#endif
}
