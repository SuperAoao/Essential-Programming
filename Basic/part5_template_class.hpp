#pragma once
#include <initializer_list>
#include <type_traits>
template <typename T>
class MyArray
{
	using iterator = T*;
	using const_iterator = const T*;
public:
	MyArray(size_t size)
	{
		if (size)
		{
			m_data = new T[size];
		}
		else
		{
			m_data = nullptr;
		}
	}
	MyArray(const std::initializer_list<T>& list);
	~MyArray();
	iterator begin() const;
	const_iterator cbegin() const;
private:
	T* m_data;
};
template <typename T>
MyArray<T>::~MyArray()
{
	if (m_data)
	{
		delete[] m_data;
	}
}

template <typename T>
typename MyArray<T>::iterator MyArray<T>::begin() const
{
	return m_data;
}

template <typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const
{
	return m_data;
}

template <typename T>
MyArray<T>::MyArray(const std::initializer_list<T>& list)
{
	if (list.size())
	{
		unsigned int count = 0;
		m_data = new T[list.size()];
		// ›Õ»°ºº ı£¨
		if (std::is_pointer<T>)
		{
			for (const val&: list)
			{
				m_data[count++] = *val;
			}
		}
	}
}