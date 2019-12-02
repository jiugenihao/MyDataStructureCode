/*
**功能描述：游戏基础数据类型定义
**文件说明：
**作    者：jiuge
**创建时间：2019-11-28
**修    改：
**严禁使用bool标准类型
//*/

#ifndef __COMMON_TYPE_H__
#define __COMMON_TYPE_H__

#ifdef _WIN32

	///////////////////////
	// 标准数据类型定义 - WIN32
	///////////////////////

	// void型
	typedef	void				VOID;			// - 32

	// char型
	typedef unsigned char		UCHAR;			// - 8
	typedef char				CHAR;			// - 8

	// int型
	typedef unsigned short		USHORT;			// - 16
	typedef short				SHORT;			// - 16
	typedef unsigned int		UINT;			// - 32
	typedef int					INT;			// - 32
	typedef __int64				LLONG;			// - 64
	typedef unsigned __int64	ULLONG;			// - 64

	// bool型
	typedef INT					BOOL;			// - 32

	// float型
	typedef float				FLOAT;			// - 32
	typedef double				DOUBLE;			//  -64

#else
	///////////////////////
	// 标准数据类型定义 - LINUX64
	///////////////////////

	// void型
	typedef void				VOID;			// - 32

	// char型
	typedef unsigned char		UCHAR;			// - 8
	typedef char				CHAR;			// - 8

	// int型
	typedef unsigned short		USHORT;			// - 16
	typedef short				SHORT;			// - 16
	typedef unsigned int		UINT;			// - 32
	typedef int					INT;			// - 32
	typedef long long			LLONG;			// - 64  ! WIN32 long型为32
	typedef unsigned long long	ULLONG;			// - 64

	// bool型
	typedef INT					BOOL;			// - 32

	// float型
	typedef float				FLOAT;			// - 32
	typedef double				DOUBLE;			// - 64	

#endif

#define BITS_PER_INT 32
#define POW_INT_2 5

///////////////////////
// bool值定义
///////////////////////
#define TRUE 1		// - 真
#define FALSE 0		// - 假


//根据指针值删除内存(malloc分配空间)
#ifndef SAFE_FREE
#define SAFE_FREE(x)	if( (x)!=nullptr ) { free (x); (x)=nullptr; }
#endif

//根据指针值删除内存(new分配空间)
#ifndef SAFE_DELETE
#define SAFE_DELETE(x)	if( (x)!=nullptr ) { delete (x); (x)=nullptr; }		
#endif

//根据指针值删除数组类型内存(new分配块空间)
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x)	if( (x)!=nullptr ) { delete[] (x); (x)=nullptr; }		
#endif

#endif
