#pragma once
/*
**文件名称：StringConvert.h
**功能描述：
**文件说明：
**作    者：jiuge
**创建时间：2019-12-5
**修    改：
//*/

#include <math.h>
namespace MyString 
{
	/////////////////////////////////////////////////////////////////////////////////
	// Convert integer to string
	//
	// value
	// Value to be converted to a string.
	// str
	// Array in memory where to store the resulting null - terminated string.
	// base
	// Numerical base used to represent the value as a string, between 2 and 36, 
	// where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
	// Returan Value
	// A pointer to the resulting null-terminated string,same as parameter str.
	/////////////////////////////////////////////////////////////////////////////////
	char* itoa(int value, char* str, int base)
	{
		if (nullptr == str)
		{
			return nullptr;
		}

		if (value < 0)
		{
			*str++ = '-';
			value = -value;
		}

		int temp = 0;
		bool is_zero = true;

		// 1个int变量最大是2^32-1 所以16进制最大是8位数，10进制最大10位数，8进制最大16位数，2进制最大32位数
		switch (base)
		{
		case 16:
			for (int i = 0; i < 8; ++i)
			{
				temp = int(value / pow(16, 7 - i));
				if (0 != temp)
				{
					is_zero = false;	// 用来优化掉开始为0的数
				}
				if (!is_zero)
				{
					if (0 <= temp && temp < 10)
					{
						*str++ = temp + '0';
					}
					else
					{
						*str++ = temp - 10 + 'A';
					}
					value = value % int(pow(16, 7 - i));
				}
				
			}
			
			break;
		case 10:
			for (int i = 0; i < 10; ++i)
			{
				temp = int(value / pow(10, 9 - i));
				if (0 != temp)
				{
					is_zero = false;	// 用来优化掉开始为0的数
				}
				if (!is_zero)
				{
					*str++ = temp + '0';
					value = value % int(pow(10, 9 - i));
				}
			}
			break;
		case 8:
			for (int i = 0; i < 16; ++i)
			{
				temp = int(value / pow(8, 15 - i));
				if (0 != temp)
				{
					is_zero = false;	// 用来优化掉开始为0的数
				}
				if (!is_zero)
				{
					*str++ = temp + '0';
					value = value % int(pow(8, 15 - i));
				}
			}
			break;
		case 2:
			for (int i = 0; i < 32; ++i)
			{
				temp = int(value / pow(2, 31 - i));
				if (0 != temp)
				{
					is_zero = false;	// 用来优化掉开始为0的数
				}
				if (!is_zero)
				{
					*str++ = temp + '0';
					value = value % int(pow(2, 31 - i));
				}
			}
			break;
		default:
			break;
		}

		*str += '\0';
		return str;
	}

	/////////////////////////////////////////////////////////////////////////////////
	// Convert string to integer
	//
	// str
	// Array in memory where to store the resulting null - terminated string.
	// Returan Value
	// On success, the function returns the converted integral number as an int value.
	// If the converted value would be out of the range of representable values by an int, 
	// it causes undefined behavior.See strtol for a more robust cross - platform alternative when this is a possibility.
	/////////////////////////////////////////////////////////////////////////////////
	int atoi(const char* str)
	{
		if (nullptr == str)
			return -1;

		int len = strlen(str);
		bool isNegative = false;
		int num = 0;

		if ('-' == str[0])
			isNegative = true;

		for (int i = 0; i < len; ++i)
		{
			int temp = str[i] - '0';
			if (0 <= temp && temp < 10)
			{
				num += temp * int(pow(10, len - i - 1));
			}
		}

		if (isNegative)
			num = -num;
		return num;
	}
}

