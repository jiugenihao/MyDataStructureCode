#include "pch.h"
#include "StringSplit.h"
using namespace MyString;

StringSplit::StringSplit(void)
{
	str    = nullptr;
	sep    = nullptr;
	type   = eSplitType::eST_Unknown;
	num	   = 0;
	values = nullptr;
}

StringSplit::StringSplit(const char* _str, const char* _sep) throw(const char*)
{
	_Separate(_str, _sep);
}

StringSplit::~StringSplit(void)
{
	_Clear();
	if (this->str) free(str);
	if (this->sep) free(sep);
}

int32_t StringSplit::ConvertToInt(void)
{
	if (!this->str || !this->sep) return -1;
	_Clear();
	this->type = eSplitType::eST_Int;
	this->num = 0;
	char* src = strdup(this->str);
	char* p1 = strtok(src, this->sep);
	while (p1)
	{
		++this->num;
		p1 = strtok(nullptr, this->sep);
	}
	free(src);
	if (this->num == 0) return 0;

	this->values = new int32_t[this->num];
	uint32_t idx = 0;
	src = strdup(this->str);
	char* p = strtok(src, this->sep);
	while (p && idx < this->num)
	{
		((int32_t*)this->values)[idx] = atoi(p);
		++idx;
		p = strtok(nullptr, this->sep);
	}
	free(src);
	return idx;
}

int32_t StringSplit::ConvertToBigInt(void)
{
	if (!this->str || !this->sep) return -1;
	_Clear();
	this->type = eSplitType::eST_BigInt;
	this->num = 0;
	char* src = strdup(this->str);
	char* p1 = strtok(src, this->sep);
	while (p1)
	{
		++this->num;
		p1 = strtok(nullptr, this->sep);
	}
	free(src);
	if (this->num == 0) return 0;

	this->values = new int64_t[this->num];
	uint32_t idx = 0;
	src = strdup(this->str);
	char* p = strtok(src, this->sep);
	while (p && idx < this->num)
	{
		((int64_t*)this->values)[idx] = strtoll(p, nullptr, 10);
		++idx;
		p = strtok(nullptr, this->sep);
	}
	free(src);
	return idx;
}

int32_t StringSplit::ConvertToFloat(void)
{
	if (!this->str || !this->sep) return -1;
	_Clear();
	this->type = eSplitType::eST_Float;
	this->num = 0;
	char* src = strdup(this->str);
	char* p1 = strtok(src, this->sep);
	while (p1)
	{
		++this->num;
		p1 = strtok(nullptr, this->sep);
	}
	free(src);
	if (this->num == 0) return 0;

	this->values = new float[this->num];
	uint32_t idx = 0;
	src = strdup(this->str);
	char* p = strtok(src, this->sep);
	while (p && idx < this->num)
	{
		((float*)this->values)[idx] = (float)atof(p);
		++idx;
		p = strtok(nullptr, this->sep);
	}
	free(src);
	return idx;
}

int32_t StringSplit::ConvertToString(void)
{
	if (!this->str || !this->sep) return -1;
	_Clear();
	this->type = eSplitType::eST_String;
	this->num = 0;
	char* src = strdup(this->str);
	char* p1 = strtok(src, this->sep);
	while (p1)
	{
		++this->num;
		p1 = strtok(nullptr, this->sep);
	}
	free(src);
	if (this->num == 0) return 0;

	this->values = new char[this->num * MAX_SPLIT_STR_BUF_LEN];
	uint32_t idx = 0;
	src = strdup(this->str);
	char* p = strtok(src, this->sep);
	while (p && idx < this->num)
	{
		size_t len = strlen(p) + 1 < (MAX_SPLIT_STR_BUF_LEN - 1) ? strlen(p) : (MAX_SPLIT_STR_BUF_LEN-1);
		memcpy(&((char*)values)[idx * MAX_SPLIT_STR_BUF_LEN], p, len);
		((char*)values)[idx * MAX_SPLIT_STR_BUF_LEN + len] = '\0';
		++idx;
		p = strtok(nullptr, this->sep);
	}
	free(src);
	return idx;
}

int32_t StringSplit::Count(void) const
{
	return this->num;
}

int32_t StringSplit::GetInt(uint32_t idx) const throw(const char*)
{
	if (this->type != eSplitType::eST_Int)
		throw "StringSplit::GetInt type nomatch!!!";
	if (idx >= num)
		throw "StringSplit::GetInt index overflow!!!";
	return ((int32_t*)values)[idx];
}

int64_t StringSplit::GetBigInt(uint32_t idx) const throw(const char*)
{
	if (this->type != eSplitType::eST_BigInt)
		throw "StringSplit::GetBigInt type nomatch!!!";
	if (idx >= num)
		throw "StringSplit::GetBigInt index overflow!!!";
	return ((int64_t*)values)[idx];
}

float StringSplit::GetFloat(uint32_t idx) const throw(const char*)
{
	if (this->type != eSplitType::eST_Float)
		throw "StringSplit::GetFloat type nomatch!!!";
	if (idx >= num)
		throw "StringSplit::GetFloat index overflow!!!";
	return ((float*)values)[idx];
}

const char* StringSplit::GetString(uint32_t idx) const throw(const char*)
{
	if (this->type != eSplitType::eST_String)
		throw "StringSplit::GetString type nomatch!!!";
	if (idx >= num)
		throw "StringSplit::GetString index overflow!!!";
	return &((char*)values)[idx * MAX_SPLIT_STR_BUF_LEN];
}

void StringSplit::_Separate(const char* _str, const char* _sep)
{
	if (!_str || !_sep)
		throw "_str OR _sep is NULL!!!";
	this->str = strdup(_str);
	this->sep = strdup(_sep);
	this->type = eSplitType::eST_Unknown;
	this->values = nullptr;
	this->num = 0;
}

void StringSplit::_Clear(void)
{
	if (this->values)
	{
		switch (this->type)
		{
		case eSplitType::eST_Int:	 delete[](int32_t*)values; break;
		case eSplitType::eST_BigInt: delete[](int64_t*)values; break;
		case eSplitType::eST_Float:  delete[](float*)values; break;
		case eSplitType::eST_String: delete[](char*)values; break;
		default:
			throw "destroy StringSplit object type UNKNOWN!!!";
			break;
		}

		this->values = nullptr;
	}
}
