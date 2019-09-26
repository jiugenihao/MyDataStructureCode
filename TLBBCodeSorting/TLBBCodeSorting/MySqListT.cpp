#include "pch.h"
#include "MySqListT.h"

template <class T>
MySqListT<T>::MySqListT(int size)
{
	m_Size = size > MAX_SQLIST_SIZE ? size : MAX_SQLIST_SIZE;
	m_pData = new T[m_Size];
	m_Len = 0;
}

template <class T>
MySqListT<T>::MySqListT(T value[], int len)
{
	if (len > 0)
	{
		m_Size = len * 2;
		m_pData = new T[m_Size];
		
		for (int i = 0; i < len; ++i)
		{
			m_pData[i] = value[i];
		}
		m_Len = len;
	}
}

template <class T>
MySqListT<T>::~MySqListT()
{
	SAFE_DELETE_ARRAY(m_pData);
	//delete[] m_pData;
}

template <class T>
bool MySqListT<T>::IsEmpty()
{
	return (m_Len == 0);
}

template <class T>
int MySqListT<T>::Len()
{
	return m_Len;
}

template <class T>
int MySqListT<T>::Capacity()
{
	return m_Size;
}

template <class T>
bool MySqListT<T>::Get(int pos, T& value)
{
	if (0 <= pos && pos < m_Len)
	{
		value = m_pData[pos];
		return true;
	}
	return false;
}

template <class T>
bool MySqListT<T>::Set(int pos, T value)
{
	if (0 <= pos && pos < m_Len)
	{
		m_pData[pos] = value;
		return true;
	}
	return false;
}

template <class T>
void MySqListT<T>::Insert(int pos, T value)
{
	if (m_Len >= m_Size)
	{
		T* tmp = m_pData;
		m_pData = new T[m_Size * 2];
		for (int i = 0; i < m_Size; ++i)
		{
			m_pData[i] = tmp[i];
		}
		m_Size *= 2;

		// free original
		delete tmp;
		tmp = nullptr;
	}
	if (pos < 0) pos = 0;
	if (pos > m_Len) pos = m_Len;
	for (int i = m_Len - 1; i >= pos; --i)
	{
		m_pData[i + 1] = m_pData[i];
	}
	m_pData[pos] = value;
	m_Len++;
}

template <class T>
void MySqListT<T>::Insert(T value)
{
	Insert(m_Len, value);
}

// ɾ����posλ��Ԫ�أ�pos֮���Ԫ�ض�Ҫǰ�ƣ����һ��Ԫ��ǰ�ƺ󱣴���m_Len-2��λ�ã�����m_Len-1λ�õ�
// ������ԭ����Ӧ������Ҫ�ͷŵ��ģ�vector��erase��destroy�����һ��Ԫ�ص�
template <class T>
bool MySqListT<T>::Remove(int pos, T& value)
{
	if (0 <= pos && pos < m_Len)
	{
		value = m_pData[pos];

		for (int i = pos; i < m_Len; ++i)
		{
			m_pData[i] = m_pData[i + 1];
		}
		
		m_Len--;			// ��С���ȣ����һ��Ԫ�ؾͲ��������ڱ����ˣ����Ǵ���и�λ�û��������ݵ�

		return true;
	}

	return false;
}

template <class T>
void MySqListT<T>::Clear()
{
	m_Len = 0;
}

template<class T>
int MySqListT<T>::Index(T value)
{
	for (int i = 0; i < m_Len; ++i)
	{
		if (m_pData[i] == value)
			return i;
	}
	return -1;
}

template<class T>
bool MySqListT<T>::Contain(T value)
{
	return Index(value)!=-1;
}

template<class T>
bool MySqListT<T>::Remove(T value)
{
	for (int i = 0; i < m_Len; ++i)
	{
		if (m_pData[i] == value)
		{
			for (int j = i; j < m_Len; ++j)
			{
				// m_Len<m_Size �������ﲻ���±�Խ��
				m_pData[j] = m_pData[j + 1];
			}
			m_Len--;
			return true;
		}
	}
	return false;
}

template<class T>
void MySqListT<T>::RemoveAll(T value)
{
	// �Ӻ���ǰɾ�������Ͳ���ʧЧ��
	for (int i = m_Len - 1; i >= 0; --i)
	{
		if (m_pData[i] == value)
		{
			for (int j = i; j < m_Len; ++j)
			{
				m_pData[j] = m_pData[j + 1];
			}
			m_Len--;
		}
	}
	
}

template<class T>
bool MySqListT<T>::Replace(T v1, T v2)
{
	int pos = Index(v1);
	if (pos >= 0)
	{
		m_pData[pos] = v2;
		return true;
	}
	return false;
}

template<class T>
void MySqListT<T>::ReplaceAll(T v1, T v2)
{
	for (int i = 0; i < m_Len; ++i)
	{
		if (m_pData[i] == v1)
		{
			m_pData[i] = v2;
		}
	}
}

//template <class T>
//ostream& operator << (ostream& out, MySqListT<T> list)
//{
//	out << "output all elements:" << endl;
//	if (list.m_Len > 0)
//	{
//		out << list.m_pData[0];
//		for (int i = 1; i < list.m_Len; ++i)
//		{
//			out << "," << list.m_pData[i];
//		}
//		out << endl;
//	}
//	return out;
//}