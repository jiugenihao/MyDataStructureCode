/*
*文件名称：CommonDefine.h
**功能描述：服务器通用定义
**文件说明：
**作    者：jiuge
**创建时间：2019-11-28
**修    改：
//*/
#ifndef __COMMON_DEFINE_H__
#define __COMMON_DEFINE_H__

#include "CommonType.h"

////////////////////////////////////////////////
// 警告关闭
////////////////////////////////////////////////
#ifdef _WIN32
#pragma warning(disable:4100)	//unreferenced formal parameter
#pragma warning(disable:4127)	//conditional expression is constant
#pragma warning(disable:4189)	//local variable is initialized but no referenced
#pragma warning(disable:4366)	//The result of the unary 'operator' operator may be unaligned
#pragma warning(disable:4251)	//'identifier':class 'type' needs to have all-interface to be used by clients of class 'type2'
#pragma warning(disable:4505)	//'function':unreferenced local function has been removed
#pragma warning(disable:4918)	//'character':invalid character in pragma optimization list
#pragma warning(disable:4996)	//'function':was declared deprecated

#endif


////////////////////////////////////////////////
// 操作系统头文件
////////////////////////////////////////////////
#ifdef _WIN32
#include <Windows.h>
#include <crtdbg.h>
#include <stdio.h>
#include <time.h>
#include <direct.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <io.h>
#include <new.h>
#include <string.h>
#include <process.h>
#include <locale.h>

#else

#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/socket.h>
#include <dirent.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include <sys/utsname.h>
#include <dlfcn.h>
#include <math.h>
#include <stdarg.h>
#include <new>
#include <iconv.h>
#include <locale.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>

#endif


////////////////////////////////////////////////
// 重定义数据类型
////////////////////////////////////////////////
#if defined(_WIN32)
typedef DWORD		ThreadID;
#elif defined(__LINUX__)
typedef pthread_t	ThreadID;
typedef VOID*		HANDLE;
#endif


#endif 

