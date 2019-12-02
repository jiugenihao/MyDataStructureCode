/*
**�����������̷߳�װ��
**�ļ�˵����
**��    �ߣ�jiuge
**����ʱ�䣺2019-11-28
**��    �ģ�
*/

#pragma once

#include "CommonDefine.h"

#if defined(_WIN32)
	DWORD WINAPI ThreadProcess(VOID* pParam);
#elif defined(__LINUX__)
	VOID* ThreadProcess(VOID* pParam);
#endif

enum class ThreadStatus
{
	STATUS_READY = 0,		// ׼��
	STATUS_RUNNING,			// ����
	STATUS_EXITING,			// �����˳�
	STATUS_EXIT,			// ��Ч
};

class MyThread
{
public:
	MyThread();
	virtual ~MyThread();

public:
	// start thread
	BOOL			Start();

	// exit thread
	VOID			Exit(VOID* retval = nullptr);

	// run thread
	virtual VOID	Run() {};

	// stop thread
	virtual VOID	Stop() {};

	// get threadid
	ThreadID		GetTID() { return m_ThreadID; }
	
	// get thread status
	ThreadStatus	GetThreadStatus() { return m_Status; }

	// set thread status
	VOID			SetThreadStatus(ThreadStatus status) { m_Status = status; }

private:
	ThreadStatus	m_Status;
	ThreadID		m_ThreadID;
#ifdef _WIN32
	HANDLE			m_hThread;
#endif // _WIN32

};

