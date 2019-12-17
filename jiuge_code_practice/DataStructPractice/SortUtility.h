/////////////////////////////////////////
//�ļ����ƣ�SortUtility.h
//���������������㷨
//        
/////////////////////////////////////////
#pragma once

namespace SortUtility
{
	// ����Ԫ��
	void Swap(int* a, int* b)
	{
		int temp = *b;
		*b = *a;
		*a = temp;
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---ֱ�Ӳ�������---����
	// array[len]��������
	// array[0...i-1]Ϊ��������
	// array[i]Ϊ�������������е�Ԫ��
	// array[i+1...len-1]Ϊ���������������
	// 1.ʹ��һ���ֲ���������array[i],�䵱�ڱ�
	// 2.�ڵ�ǰ������array[0..i-1]�в���array[i]����ȷ����λ��k(0��k��i-1)��
	// 3.��array[k����i-1]�еļ�¼������һ��λ�ã��ڳ�kλ���ϵĿռ����array[i]
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void InsertSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		// ���ѭ���ӵڶ���Ԫ�ؿ�ʼ list[0]Ϊ��������
		for (int i = 1; i < len; ++i)
		{
			if (list[i] < list[i - 1])
			{
				T sentry = list[i];	// �ڱ�
				int k = i - 1;
				for ( ; k >= 0 && sentry < list[k]; --k)
				{
					list[k + 1] = list[k];
				}

				list[k + 1] = sentry;	// ��Ϊѭ�������һ��--k��,�������һ����Ҫ�ӻ���
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---ϣ������---����
	// array[0...len-1]��������
	// 1.��һ���������зֳ������飬ÿ����������ɾ���delta��Ԫ����ɣ�delta��Ϊ������
	//   ��һ�����ڲ���ֱ�Ӳ��������㷨��������
	// 2.delta�ĳ�ֵͨ��Ϊ�������г��ȵ�һ�룬�Ժ�ÿ����������С�����ֵΪ1������
	//   ����delta�ļ�С������Ҳ���٣�����Ԫ�ظ������ӣ�����������ӽ�����
	// 3.������Ϊ1ʱ��ֻ��1�飬Ԫ�����������У��ٽ���һ��ֱ�Ӳ������򼴿�
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void ShellSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		// �����зֳ�delta�飬��������
		for (int delta = len / 2; delta > 0; delta /= 2)
		{
			// һ�˷������飬һ��Ԫ�ؾ���delta
			for (int i = delta; i < len; ++i)
			{
				// ���ڽ���ֱ�Ӳ�������
				T sentry = list[i];
				int k = 0;
				for (k = i - delta; k >= 0 && sentry < list[k]; k -= delta)
				{
					list[k + delta] = list[k];
				}
				list[k + delta] = sentry;	// ��Ϊѭ�������һ��k = k - delta��, ����������Ҫ�ӻ���
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---ð������---����
	// �Ƚ����������ؼ��ֵ�ֵ����������򽻻���
	// ������������ÿһ�˽���ɨ����������������ؼ��ֽ��������λ�ã��������ݴ�ˮ��ð��һ��
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void BubbleSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		bool exchange = true;
		for (int i = 1; i < len && exchange; ++i)
		{
			exchange = false;
			for (int j = 0; j < len - i; ++j)
			{
				if (list[j] > list[j + 1])
				{
					Swap(&list[j], &list[j + 1]);
					exchange = true;
				}
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---��������---����
	// 1.������������ѡȡһ��ֵ��Ϊ�Ƚϻ�׼ֵ
	// 2.ÿ�˴��������е����˿�ʼ����ִ�У���С�ڻ�׼ֵ��Ԫ�ؽ���������ǰ�ˣ����ڻ�׼
	//   ֵ��Ԫ�ؽ��������к�ˣ���������֮���λ�þͳ�Ϊ��׼ֵ������λ��(i==j)
	// 3.ͬʱ�����б�����Ϊ���������У�����ͬ���ķ��������������н�������ֱ��������
	//   �ĳ���Ϊ1�����������
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void QuickSort(T list[], int len, int low, int high)
	{
		if (0 <= low && low < len && 0 <= high && high < len && low < high)
		{
			int i = low;
			int j = high;
			T vote = list[i];
			while (i != j)
			{
				while (i < j && vote < list[j])
				{
					j--;
				}
				if (i < j) list[i++] = list[j];
				while (i < j && list[i] <= vote)
				{
					i++;
				}
				if (i < j) list[j--] = list[i];
			}
			list[i] = vote;
			QuickSort(list, len, low, j - 1);
			QuickSort(list, len, i + 1, high);
		}
	}
	template <class T>
	void QuickSort(T list[], int len)
	{
		if (len <= 0)
			return;
		QuickSort(list, len, 0, len - 1);
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ѡ������---ֱ��ѡ������---����
	// 1.��һ�˴�n��Ԫ�ص�����������ѡ���ؼ���ֵ��С��Ԫ�أ����������е���ǰ��λ�á�
	// 2.��һ���ٴ�n-1��Ԫ����ѡ���ؼ���ֵ��С��Ԫ�أ����ڴ�ǰ��λ�á�
	// 3.�Դ����ƣ�����n-1���������
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void SelectSort(T list[], int len)
	{
		if (len <= 0)
			return;
		for (int i = 0; i < len - 1; ++i)
		{
			int min = i;
			for (int j = i + 1; j < len; ++j)
			{
				if (list[j] < list[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				Swap(&list[i], &list[min]);
			}
			
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---������---�󶥶�---����
	// 1.���������н����ɶ�����
	// 2.����ѡ������˼·��ÿ�˽����ڵ㽻��������ٽ�ʣ����������е����ɶ�����
	// 3.����ظ���ֱ���������
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void MaxHeapify(T list[], int i, int len)
	{
		int left  = i * 2 + 1;
		int right = i * 2 + 2;
		int large = i;

		if (left < len && list[left] > list[large])
		{
			large = left;
		}
		if (right < len && list[right] > list[large])
		{
			large = right;
		}
		if (large != i)
		{
			Swap(&list[large], &list[i]);
			MaxHeapify(list, large, len);
		}
	}
	template <class T>
	void CreateMaxHeap(T list[], int len)
	{
		int i = len / 2 - 1;
		for ( ; i >= 0; --i)
		{
			MaxHeapify(list, i, len);
		}
	}
	template <class T>
	void MaxHeapSort(T list[], int len)
	{
		if (len <= 0)
			return;
		CreateMaxHeap(list, len);

		for (int i = len - 1; i > 0; --i)
		{
			Swap(&list[0], &list[i]);
			MaxHeapify(list, 0, i);
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---������---С����---����
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void MinHeapify(T list[], int start, int end)
	{
		// �������ڵ�ָ����ӽڵ�ָ��
		int dad = start;
		int son = dad * 2 + 1;
		while (son <= end)  //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
		{
			// �ȱȽ������ӽڵ��С��ѡ����С��
			if (son + 1 <= end && list[son] > list[son + 1])
				son++;

			// ������ڵ����ӽڵ���������ϣ�ֱ����������
			if (list[dad] <= list[son]) 
				return;
			else
			{
				//���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
				Swap(&list[dad], &list[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	}
	
	template <class T>
	void MinHeapSort(T list[], int len)
	{
		if (len <= 0)
			return;

		int i = 0;
		for (i = len / 2 - 1; i >= 0; i--)
			MinHeapify(list, i, len - 1);

		//�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ�������������µ�����ֱ���������
		for (i = len - 1; i > 0; i--)
		{
			Swap(&list[0], &list[i]);
			MinHeapify(list, 0, i - 1);
		}
	}


} // namespace SortUtility
