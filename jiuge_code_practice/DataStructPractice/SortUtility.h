/////////////////////////////////////////
//�ļ����ƣ�SortUtility.h
//���������������㷨
//        
/////////////////////////////////////////
#pragma once
#include "BaseDefine.h"
namespace SortUtility
{
	enum class SortType
	{
		ST_Insert = 1,
		ST_Shell,
		ST_Bubble,
		ST_Quick,
		ST_Select,
		ST_Heap,
		ST_Merge,
	};
	// ����Ԫ��
	template <class T>
	void Swap(T* a, T* b)
	{
		T temp = *b;
		*b = *a;
		*a = temp;
	}

	// ��ӡͷ
	void PrintHead(SortType type)
	{
		switch (type)
		{
		case SortUtility::SortType::ST_Insert:
			cout << "ֱ�Ӳ�������" << endl;
			break;
		case SortUtility::SortType::ST_Shell:
			cout << "ϣ������" << endl;
			break;
		case SortUtility::SortType::ST_Bubble:
			cout << "ð������" << endl;
			break;
		case SortUtility::SortType::ST_Quick:
			cout << "��������" << endl;
			break;
		case SortUtility::SortType::ST_Select:
			cout << "ֱ��ѡ������" << endl;
			break;
		case SortUtility::SortType::ST_Heap:
			cout << "������" << endl;
			break;
		case SortUtility::SortType::ST_Merge:
			cout << "�鲢����" << endl;
			break;
		default:
			break;
		}
	}

	// ��ӡβ
	void PrintTail()
	{
		cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
		cout << endl;
	}

	// ��ӡԪ��
	template <class T>
	void Print(T list[], int len, int time)
	{
		if (len <= 0) return;
		cout << "��" << setw(3) << time << " �ˣ� ";
		for (int i = 0; i < len; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
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
	// 0 1 2 ... k-1   k     k+1 k+2 ... i-1
	// |_ _ _ _ _ |    |      |_ _ _ _ _ _|
	//  ������������  ������Ԫ��   ���������������
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void InsertSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		PrintHead(SortType::ST_Insert);
		int time = 0;					// ����
		Print(list, len, time++);

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
			Print(list, len, time++);
		}

		PrintTail();
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---ϣ������---����
	// array[0...len-1]��������
	// 1.��һ���������зֳ������飬ÿ����������ɾ���delta��Ԫ����ɣ�delta��Ϊ������
	//   ��һ�����ڲ���ֱ�Ӳ��������㷨��������
	// 2.delta�ĳ�ֵͨ��Ϊ�������г��ȵ�һ�룬�Ժ�ÿ����������С�����ֵΪ1������
	//   ����delta�ļ�С������Ҳ���٣�����Ԫ�ظ������ӣ�����������ӽ�����
	// 3.������Ϊ1ʱ��ֻ��1�飬Ԫ�����������У��ٽ���һ��ֱ�Ӳ������򼴿�
	// 54  18  66  87  36  12  54  81  15  76
	//  | _ _ _ _ _ _ _ _ _ |
	//    18| _ _ _ _ _ _ _ _ _ |54
	//        66| _ _ _ _ _ _ _ _ __|81
	//            87| _ _ _ _ _ _ _ _ _ |15
	//                36| _ _ _ _ _ _ _ _ _ |76
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void ShellSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		PrintHead(SortType::ST_Shell);
		int time = 0;					// ����
		Print(list, len, time++);

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
			Print(list, len, time++);
		}
		PrintTail();
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

		PrintHead(SortType::ST_Bubble);
		int time = 0;					// ����
		Print(list, len, time++);

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
			Print(list, len, time++);
		}
		PrintTail();
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
	void QuickSort(T list[], int len, int low, int high, int& time)
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
			Print(list, len, time++);
			QuickSort(list, len, low, j - 1, time);
			QuickSort(list, len, i + 1, high, time);
		}
	}
	template <class T>
	void QuickSort(T list[], int len)
	{
		if (len <= 0)
			return;

		PrintHead(SortType::ST_Quick);
		int time = 0;					// ����
		Print(list, len, time++);

		QuickSort(list, len, 0, len - 1, time);
		PrintTail();
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

		PrintHead(SortType::ST_Select);
		int time = 0;					// ����
		Print(list, len, time++);

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
			Print(list, len, time++);
		}
		PrintTail();
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ��������---������---�󶥶�---����
	// 1.���������н����ɶ�����
	// 2.����ѡ������˼·��ÿ�˽����ڵ㽻��������ٽ�ʣ����������е����ɶ�����
	// 3.����ظ���ֱ���������
	// �ݹ��㷨�Զ�����
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

		PrintHead(SortType::ST_Heap);
		int time = 0;					// ����
		Print(list, len, time++);

		CreateMaxHeap(list, len);
		Print(list, len, time++);

		for (int i = len - 1; i > 0; --i)
		{
			Swap(&list[0], &list[i]);
			MaxHeapify(list, 0, i);
			Print(list, len, time++);
		}
		PrintTail();
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

		PrintHead(SortType::ST_Heap);
		int time = 0;					// ����
		Print(list, len, time++);

		int i = 0;
		for (i = len / 2 - 1; i >= 0; i--)
			MinHeapify(list, i, len - 1);
		Print(list, len, time++);

		//�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ�������������µ�����ֱ���������
		for (i = len - 1; i > 0; i--)
		{
			Swap(&list[0], &list[i]);
			MinHeapify(list, 0, i - 1);
			Print(list, len, time++);
		}
		PrintTail();
	}


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// �鲢����---��·�鲢����
	// N��Ԫ�ص��������пɿ�������N������Ϊ1��������������ɣ����������ڵ�����������
	// �ϲ���һ������������У�ֱ���ϲ���һ�����У��������
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ���ι鲢���������������������й鲢��һ����������
	// low low+1 ... mid mid+1 mid+2 ... high
	// |_ _ _ _ _ _ _ |  |_ _ _ _ _ _ _ _ _|
	// i                 j
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void Merge(T list[], T aux[], int low, int mid, int high)
	{
		int i = low, j = mid + 1;
		// �Ƚ�list[low...high]������aux[low...high]
		for (int k = low; k <= high; k++)
		{
			aux[k] = list[k];
		}
		
		for (int k = low; k <= high; k++)
		{
			if		(i > mid)			list[k] = aux[j++];		// �����þ���ȡ�ұ�Ԫ��
			else if (j > high)			list[k] = aux[i++];		// �Ұ���þ���ȡ���Ԫ��
			else if (aux[i] < aux[j])	list[k] = aux[i++];		// ���ߵĵ�ǰԪ��С���Ұ�ߵĵ�ǰԪ�أ�ȡ���ߵĵ�ǰԪ��
			else						list[k] = aux[j++];		// ���ߵĵ�ǰԪ�ش��ڵ����Ұ�ߵĵ�ǰԪ�أ�ȡ�Ұ�ߵĵ�ǰԪ��
		}
	}

	// ������������ȫ��Ϊ��ͳ������ʹ�ã�����ȥ��
	template <class T>
	void MergeSort(T data[], int start, int end, T aux[], int& time, int len)
	{
		if (start < end)
		{
			int mid = start + (end - start) / 2;			// �������int
			MergeSort(data, start, mid, aux, time, len);	// ����߽�������
			MergeSort(data, mid + 1, end, aux, time, len);	// ���ұ߽�������
			Merge(data, aux, start, mid, end);				// ������õ����ݺϲ�
			Print(data, len, time++);
		}
	}
	template <class T>
	void MergeSortRecursive(T list[], int len)
	{
		if (len <= 0) return;

		T* aux = new T[len];
		if (!aux) return;

		PrintHead(SortType::ST_Merge);
		int time = 0;					// ����
		Print(list, len, time++);

		MergeSort(list, 0, len - 1, aux, time, len);

		//Print(list, len, time++);
		PrintTail();

		delete[] aux;
		aux = nullptr;
	}

	//template <class T>
	//void MergeSort1(T list[], int len)
	//{
	//	if (len <= 0) return;

	//	T* aux = new T[len];
	//	if (!aux) return;

	//	//Merge(list, aux, 0, len / 2 - 1, len - 1);

	//	// 0,6,3,2,7,5,4,9,1,8  ÿ2��Ԫ�ع鲢 ���г���Ϊ1
	//	Merge(list, aux, 0, 0, 1);
	//	Merge(list, aux, 2, 2, 3);
	//	Merge(list, aux, 4, 4, 5);
	//	Merge(list, aux, 6, 6, 7);
	//	Merge(list, aux, 8, 8, 9);

	//	// step = 1
	//	//Merge(list, aux, i * 2, i * 2, i * 2 + 1);			//
	//															//
	//	// ÿ4��Ԫ�ع鲢											//
	//	Merge(list, aux, 0, 1, 3);								//
	//	Merge(list, aux, 4, 5, 7);								//
	//	Merge(list, aux, 8, 8, 9);								//
	//	//Merge(list, aux, i * 4, i * 4 + 1, i * 4 + 3);		//
	//															//
	//	// ÿ8��Ԫ�ع鲢											//
	//	Merge(list, aux, 0, 3, 7);								//
	//	Merge(list, aux, 8, 8, 9);								//
	//	//Merge(list, aux, i * 8, i * 8 + 3, i * 8 + 7);		//
	//															//
	//	// ÿ16��Ԫ�ع鲢											//
	//	Merge(list, aux, 0, 7, 9);								//
	//	//Merge(list, aux, i * 16, i * 16 + 7, i * 16 + 15);	//

	//	delete[] aux;
	//	aux = nullptr;
	//}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// ���ι鲢���������������������й鲢��һ����������
	// lenΪlist��aux�ĳ���
	// start_lΪ�����еĿ�ʼλ�ã�start_rΪ�����еĿ�ʼλ�ã�nΪ�����еĳ���
	// start_l start_l+1 ... start_r-1 start_r start_r+1 ... start_r+n-1 start_r+n
	//    |_ _ _ _ _ _ _ _ _ _ _ _|       |_ _ _ _ _ _ _ _ _ _ _ _ |
	//    i                               j
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void Merge(T list[], int len, T aux[], int start_l, int start_r, int n)
	{
		int i = start_l, j = start_r, k = start_l;
		while (i < start_r && j < start_r + n && j < len)
		{
			if (list[i] < list[j])
			{
				aux[k++] = list[i++];
			}
			else
			{
				aux[k++] = list[j++];
			}
		}
		while (i < start_r)
		{
			aux[k++] = list[i++];
		}
		while (j < start_r + n && j < len)
		{
			aux[k++] = list[j++];
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// һ�˹鲢����
	// lenΪlist��aux�ĳ��ȣ�nΪ�����еĳ���
	// 0 ... n-1 n n+1 ... 2n-1 2n 2n+1 ... 3n-1 ... ... xn ... len-1
	// |_ _ _ |  | _ _ _ _ _ |  |_ _ _ _ _ _ _|          |_ _ _ _ |
	// i         i+n     i+2n-1 i+2n                     i+xn
	// |_ _ _ _ _ _ _ _ _ _ _|  |_ _ _ _ _ _ _ _ _| |_ _ _ _ _ _ _|
	//       Merge                    Merge              Merge
	// ����ͼ�����Ƶ��� i+2n<len ==> i < len-2n
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void MergePass(T list[], int len, T aux[], int n)
	{
		int i = 0;
		//while (i < len - n * 2 + 1)
		while (i + n * 2 - 1 < len - 1)
		{
			Merge(list, len, aux, i, i + n, n);
			i += n * 2;
		}
		if (i + n < len - 1)
		{
			// ��һ�ι鲢
			Merge(list, len, aux, i, i + n, n);
		}
		else
		{
			// ��ʣ��Ԫ�ش�list���Ƶ�aux
			for (int j = i; j < len; j++)
			{
				aux[j] = list[j];
			}
		}
	}
	template <class T>
	void MergeSort(T list[], int len)
	{
		if (len <= 0) return;

		T* aux = new T[len];
		if (!aux) return;

		PrintHead(SortType::ST_Merge);
		int time = 0;					// ����
		Print(list, len, time++);

		int n = 1;
		do
		{
			MergePass(list, len, aux, n);
			Print(aux, len, time++);
			n *= 2;
			if (n < len)
			{
				MergePass(aux, len, list, n);
				Print(list, len, time++);
				n *= 2;
			}
		} while (n < len);

		PrintTail();

		delete[] aux;
		aux = nullptr;
	}

} // namespace SortUtility
