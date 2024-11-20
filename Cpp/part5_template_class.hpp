#pragma once
#include <initializer_list>
#include <type_traits>
template <typename T>
struct getType
{
	using type = T;
};
template <typename T>
struct getType<T*>
{
	using type = T;
};

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
	};
	MyArray(const std::initializer_list<T>& list);
	MyArray(std::initializer_list<T>&& list);
	~MyArray();
	virtual T& operator[](unsigned int i) const
	{
		return m_data[i];
	};
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
		if (std::is_pointer<T>::value)
		{
			for (auto elem: list)
			{
				m_data[count++] = new typename getType<T>::type(*elem);
			}
		}
		else
		{
			for (const auto& elem : list)
			{
				m_data[count++] = elem;
			}
		}
	}
	else
	{
		m_data = nullptr;
	}
}

template <typename T>
MyArray<T>::MyArray(std::initializer_list<T>&& list)
{
	if (list.size())
	{
		unsigned int count = 0;
		m_data = new T[list.size()];
	
		if (std::is_pointer<T>::value)
		{
			for (auto elem : list)
			{
				m_data[count++] = elem;
				elem = nullptr;
			}
		}
		else
		{
			if (std::is_pointer<T>::value)
			{
				for (auto elem : list)
				{
					m_data[count++] = elem;
				}
			}
		}
	}
	else
	{
		m_data = nullptr;
	}
}