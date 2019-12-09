/*
**文件名称：String.h
**功能描述：字符串类
**文件说明：
**作    者：jiuge
**创建时间：2019-12-6
**修    改：
//*/
#pragma once

namespace MyString
{
	class String
	{
	public:
		String(const char* str = nullptr);
		String(const String& other);
		~String();

		int size() const;
		String& operator = (const String& other);
		
	private:
		char* m_data;
		int	  m_len;
	};

}