/*
**������������Ϸ�����������Ͷ���
**�ļ�˵����
**��    �ߣ�jiuge
**����ʱ�䣺2019-11-28
**��    �ģ�
**�Ͻ�ʹ��bool��׼����
//*/

#ifndef __COMMON_TYPE_H__
#define __COMMON_TYPE_H__

#ifdef _WIN32

	///////////////////////
	// ��׼�������Ͷ��� - WIN32
	///////////////////////

	// void��
	typedef	void				VOID;			// - 32

	// char��
	typedef unsigned char		UCHAR;			// - 8
	typedef char				CHAR;			// - 8

	// int��
	typedef unsigned short		USHORT;			// - 16
	typedef short				SHORT;			// - 16
	typedef unsigned int		UINT;			// - 32
	typedef int					INT;			// - 32
	typedef __int64				LLONG;			// - 64
	typedef unsigned __int64	ULLONG;			// - 64

	// bool��
	typedef INT					BOOL;			// - 32

	// float��
	typedef float				FLOAT;			// - 32
	typedef double				DOUBLE;			//  -64

#else
	///////////////////////
	// ��׼�������Ͷ��� - LINUX64
	///////////////////////

	// void��
	typedef void				VOID;			// - 32

	// char��
	typedef unsigned char		UCHAR;			// - 8
	typedef char				CHAR;			// - 8

	// int��
	typedef unsigned short		USHORT;			// - 16
	typedef short				SHORT;			// - 16
	typedef unsigned int		UINT;			// - 32
	typedef int					INT;			// - 32
	typedef long long			LLONG;			// - 64  ! WIN32 long��Ϊ32
	typedef unsigned long long	ULLONG;			// - 64

	// bool��
	typedef INT					BOOL;			// - 32

	// float��
	typedef float				FLOAT;			// - 32
	typedef double				DOUBLE;			// - 64	

#endif

#define BITS_PER_INT 32
#define POW_INT_2 5

///////////////////////
// boolֵ����
///////////////////////
#define TRUE 1		// - ��
#define FALSE 0		// - ��


//����ָ��ֵɾ���ڴ�(malloc����ռ�)
#ifndef SAFE_FREE
#define SAFE_FREE(x)	if( (x)!=nullptr ) { free (x); (x)=nullptr; }
#endif

//����ָ��ֵɾ���ڴ�(new����ռ�)
#ifndef SAFE_DELETE
#define SAFE_DELETE(x)	if( (x)!=nullptr ) { delete (x); (x)=nullptr; }		
#endif

//����ָ��ֵɾ�����������ڴ�(new�����ռ�)
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x)	if( (x)!=nullptr ) { delete[] (x); (x)=nullptr; }		
#endif

#endif
