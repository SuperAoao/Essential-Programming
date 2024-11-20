#include "part5_template_class.hpp"
#include <vector>
#include <type_traits>
#include <iostream>
#include <functional>
namespace mystd
{
	// 模板函数
	// 默认参数
	using default_func = std::function<void(int&)>;
	template<typename iter_type, typename func_type = default_func>
	void for_each(iter_type begin, iter_type end, func_type func = [](int& elem) { elem += 2; })
	{
		for (auto iter = begin; iter != end; ++iter)
		{
			func(*iter);
		}
	};

	// 模板成员函数
	template<typename T>
	class MyVec
	{
	public:
		template<typename T2>
		void outPut(const T2& elem);
	};
	template<typename T>
	template<typename T2>
	void MyVec<T>::outPut(const T2& elem)
	{
		std::cout << elem << std::endl;
	}
}

int main()
{

	std::vector<int> vec = { 1,2,3,4,5 };
	mystd::for_each(vec.begin(), vec.end(), [](int& val) { ++val; });
	for (int val : vec) {
		std::cout << val << std::endl;
	}
	mystd::for_each(vec.begin(), vec.end());
	for (int val : vec) {
		std::cout << val << std::endl;
	}

	mystd::MyVec<int> myVec;
	myVec.outPut<double>(3.3);
	return 0;
}