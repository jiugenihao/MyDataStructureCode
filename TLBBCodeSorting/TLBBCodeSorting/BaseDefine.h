/////////////////////////////////////////////////////////////////////////////////
//文件名称：BaseDefine.h
//功能描述：系统底层类型基础文件，无授权人员不得修改此文件内容
//版本说明：Windows操作系统需要定义宏：__WINDOWS__
//			Linux操作系统需要定义宏：__LINUX__
//修改情况：
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef __BASEDEFINE_H__
#define __BASEDEFINE_H__

#include <iostream>

using namespace std;

#pragma once


#ifndef SAFE_DELETE
#define SAFE_DELETE(x) if(NULL!=(x)){delete (x); (x)=NULL;}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) if(NULL!=(x)){delete[] (x); (x)=NULL;}
#endif


#endif