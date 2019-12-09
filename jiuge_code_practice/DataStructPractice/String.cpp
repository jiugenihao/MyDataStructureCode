#include "pch.h"
#include "String.h"
#include "BaseDefine.h"

using namespace MyString;

String::String(const char* str)
{
	if (!str)
	{
		m_len = 0;
		this->m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		m_len = strlen(str);
		this->m_data = new char[m_len + 1];
		strcpy(m_data, str);
	}
	
}

String::String(const String& other)
{
	m_len = other.size();
	this->m_data = new char[m_len + 1];
	strcpy(this->m_data, other.m_data);
}

int MyString::String::size() const
{
	return m_len;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		// 先删除原有申请的空间
		SAFE_DELETE(m_data);
		m_len = other.size();
		m_data = new char[m_len + 1];
		strcpy(m_data, other.m_data);
	}
	return *this;
}

String::~String()
{
	SAFE_DELETE(m_data);
	m_len = 0;
}
