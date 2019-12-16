/////////////////////////////////////////
//文件名称：SortUtility.h
//功能描述：排序算法
//        
/////////////////////////////////////////
#pragma once

namespace SortUtility
{
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 插入排序---直接插入排序---升序
	// array[len]乱序序列
	// array[0...i-1]为有序序列
	// array[i]为待加入有序序列的元素
	// array[i+1...len-1]为待排序的无序序列
	// 1.使用一个局部变量保存array[i],充当哨兵
	// 2.在当前有序区array[0..i-1]中查找array[i]的正确插入位置k(0≤k≤i-1)；
	// 3.将array[k．．i-1]中的记录均后移一个位置，腾出k位置上的空间插入array[i]
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void InsertSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		// 外层循环从第二个元素开始 list[0]为有序序列
		for (int i = 1; i < len; ++i)
		{
			if (list[i] < list[i - 1])
			{
				T sentry = list[i];	// 哨兵
				int k = i - 1;
				for ( ; k >= 0 && sentry < list[k]; --k)
				{
					list[k + 1] = list[k];
				}

				list[k + 1] = sentry;	// 因为循环的最后一步--k了,所以最后一个需要加回来
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 插入排序---希尔排序---升序
	// array[0...len-1]乱序序列
	// 1.将一个数据序列分成若干组，每组由相隔若干距离delta的元素组成，delta称为增量，
	//   在一个组内采用直接插入排序算法进行排序
	// 2.delta的初值通常为数据序列长度的一半，以后每趟增量逐渐缩小，最后值为1，随着
	//   增量delta的减小，组数也减少，组内元素个数增加，整个序列则接近有序。
	// 3.当增量为1时，只有1组，元素是整个序列，再进行一次直接插入排序即可
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void ShellSort(T list[], int len)
	{
		if (len <= 0)
		{
			return;
		}

		// 将序列分成delta组，增量减半
		for (int delta = len / 2; delta > 0; delta /= 2)
		{
			// 一趟分若干组，一组元素距离delta
			for (int i = delta; i < len; ++i)
			{
				// 组内进行直接插入排序
				T sentry = list[i];
				int k = 0;
				for (k = i - delta; k >= 0 && sentry < list[k]; k -= delta)
				{
					list[k + delta] = list[k];
				}
				list[k + delta] = sentry;	// 因为循环的最后一步k = k - delta了, 所以这里需要加回来
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---冒泡排序---升序
	// 比较相邻两个关键字的值，如果反序则交换。
	// 若按升序排序，每一趟将被扫描的数据序列中最大关键字交换到最后位置，就像气泡从水里冒出一样
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
					T tmp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = tmp;
					exchange = true;
				}
			}
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---快速排序---升序
	// 1.在数据序列中选取一个值作为比较基准值
	// 2.每趟从数据序列的两端开始交替执行，将小于基准值的元素交换到序列前端，大于基准
	//   值的元素交换到序列后端，介于两者之间的位置就成为基准值的最终位置(i==j)
	// 3.同时，序列被划分为两个子序列，再用同样的方法对两个子序列进行排序，直到子序列
	//   的长度为1，则完成排序
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
	// 选择排序---直接选择排序---升序
	// 1.第一趟从n个元素的数据序列中选出关键字值最小的元素，并放在序列的最前的位置。
	// 2.下一趟再从n-1个元素中选出关键字值最小的元素，放在次前的位置。
	// 3.以此类推，经过n-1趟完成排序
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
				T tmp = list[i];
				list[i] = list[min];
				list[min] = tmp;
			}
			
		}
	}

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	// 交换排序---堆排序---升序
	// 
	// 
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class T>
	void HeapSort(T list[], int len)
	{
		if (len <= 0)
			return;
	}


} // namespace SortUtility
