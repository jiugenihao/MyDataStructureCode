/////////////////////////////////////////////////////////////////////////////////
// �ļ����ƣ�StringSplit.h
// �����������ַ����ָ���󣬷ָ�ɸ�������
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseDefine.h"

#define MAX_SPLIT_STR_BUF_LEN	(512)
const char* const _STRING_DELIMITER = "|";

enum class eSplitType
{
	eST_Unknown = -1,
	eST_Int,
	eST_BigInt,
	eST_Float,
	eST_String,
};

class StringSplit
{
public:
	StringSplit(void);
	StringSplit(const char* _str, const char* _sep) throw(const char*);
	~StringSplit(void);

	int32_t ConvertToInt(void);
	int32_t ConvertToBigInt(void);
	int32_t ConvertToFloat(void);
	int32_t ConvertToString(void);
	int32_t Count(void) const;

	int32_t GetInt(uint32_t idx) const throw(const char*);
	int64_t GetBigInt(uint32_t idx) const throw(const char*);
	float GetFloat(uint32_t idx) const throw(const char*);
	const char* GetString(uint32_t idx) const throw(const char*);

private:
	void _Separate(const char* _str, const char* _sep);
	void _Clear(void);

private:
	char*		str;
	char*		sep;
	eSplitType  type;
	uint32_t	num;
	void*		values;
};


// ģ��ʵ��
// s.find_first_not_of (const string& str, size_t pos = 0) ��s�в��ҵ�һ������args�е��ַ���λ��
// s.find_first_of (const string& str, size_t pos = 0)     ��s�в���args���κ�һ���ַ���һ�γ��ֵ�λ��
// s.substr (size_t pos = 0, size_t len = npos) const	   ��s�л�ȡ��pos��ʼlen���ַ����Ӵ�
template <typename Container>
size_t MyStrTok(string& str, Container& cont, const string sep = "|")
{
	cont.clear();
	size_t size = 0;
	size_t begPos = 0;
	size_t endPos = 0;
	begPos = str.find_first_not_of(sep);
	while (begPos != string::npos)
	{
		++size;
		endPos = str.find_first_of(sep, begPos);
		if (endPos == string::npos)
		{
			endPos = str.size();
		}
		string subStr = str.substr(begPos, endPos - begPos);
		cont.push_back(subStr);
		begPos = str.find_first_not_of(sep, endPos + 1);
	}

	return size;
}

template <typename Container>
size_t MyStringTok(string& str, Container& cont, const string sep = "")
{
	cont.clear();
	size_t size = 0;
	size_t length = str.length();
	size_t begPos = 0;
	size_t endPos = 0;
	while (begPos < length)
	{
		++size;
		begPos = str.find_first_not_of(sep, begPos);
		if (begPos == string::npos)
		{
			return -1;
		}
		endPos = str.find_first_of(sep, begPos);
		if (endPos == string::npos)
		{
			endPos = length;
		}
		string subStr = str.substr(begPos, endPos - begPos);
		cont.push_back(subStr);
		begPos = endPos + 1;
	}

	return size;
}