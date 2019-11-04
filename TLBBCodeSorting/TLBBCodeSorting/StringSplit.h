/////////////////////////////////////////////////////////////////////////////////
// 文件名称：StringSplit.h
// 功能描述：字符串分割对象，分割成各种数据
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

