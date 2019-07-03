/////////////////////////////////////////////////////////////////////////////////
//�ļ����ƣ�BaseDefine.h
//����������ϵͳ�ײ����ͻ����ļ�������Ȩ��Ա�����޸Ĵ��ļ�����
//�汾˵����Windows����ϵͳ��Ҫ����꣺__WINDOWS__
//			Linux����ϵͳ��Ҫ����꣺__LINUX__
//�޸������
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