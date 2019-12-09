/*
**�ļ����ƣ�String.h
**�����������ַ�����
**�ļ�˵����
**��    �ߣ�jiuge
**����ʱ�䣺2019-12-6
**��    �ģ�
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