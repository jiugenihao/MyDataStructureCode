/////////////////////////////////////////
//�ļ����ƣ�RemoveOpe.h
//����������ɾ������
//        
/////////////////////////////////////////

#pragma once
#include "BaseDefine.h"

namespace Question
{
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	// ���⣺ɾ�����Ա�������ֵΪvalue��Ԫ��
	//+++++++++++++++++++++++++++++++++++++++++++++++++//

	// �����ķ������ŵ���������٣�ȱ�㲻�׶�
	int RemoveAll_lw(int data[], int n, int value)
	{
		if (n <= 0) return -1;

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		int removeCnt = 0;
		int loop = 0;		// ѭ������
		
		for (int i = 0; i < n - 1; i++)
		{
			loop++;
			if (data[i] == value)
			{
				for (; i < n - 1; ++i)
				{
					loop++;
					if (data[i + 1] == value)
						removeCnt++;
					else
						break;
				}
				removeCnt++;
			}
			if (removeCnt > 0)
			{
				data[i - removeCnt + 1] = data[i + 1];
			}
		}
		if (data[n - 1] == value)
			data[n - removeCnt - 1] = 0;
		for (int i = n - removeCnt; i < n; i++)
		{
			data[i] = 0;
			loop++;
		}

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		return loop;
	}

	// �ҵķ�����ȱ����������࣬�ŵ��׶������س���
	int RemoveAll_me(int data[], int& n, int value)
	{
		int loop = 0;
		
		if (n <= 0) return -1;

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		for (int i = n - 1; i >= 0; --i)
		{
			loop++;
			if (data[i] == value)
			{
				for (int j = i; j < n; ++j)
				{
					loop++;
					data[j] = data[j + 1];
				}
				n--;
			}
		}

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		return loop;
	}

	// ���ܵģ����������٣��׶���
	int RemoveAll_zq(int data[], int n, int value)
	{
		if (n <= 0) return -1;

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		int loop = 0;
		int index = 0;
		for (int i = 0; i < n - 1; i++)
		{
			loop++;
			if (data[i] != value)
				data[index++] = data[i];
		}
		for (int i = index; i < n - 1; i++)
		{
			loop++;
			data[i] = value;	// ��һ��������ɾ����ֵ���д���ȶ
		}

		for (int i = 0; i < n; ++i)
			cout << data[i] << " ";
		cout << endl;

		return loop;
	}

}
