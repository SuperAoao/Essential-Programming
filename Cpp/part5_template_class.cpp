#include "part5_template_class.hpp"
#include <vector>
#include <type_traits>
#include <iostream>
int main()
{
	std::initializer_list<int> list = { 1,2,3,4,5 };
	std::vector<int> vec(list);

	// ›Õ»°ºº ı
	int i1 = 10;
	int i2 = 20;
	std::initializer_list<int*> list_pointer = { &i1, &i2 };
	MyArray<int*> arr(list_pointer);
	for (int i = 0; i < 2; i++)
	{
		std::cout << *arr[i] << std::endl;
	}

	MyArray<int*> arrMove(std::move(list_pointer));
	for (int i = 0; i < 2; i++)
	{
		std::cout << *arrMove[i] << std::endl;
	}

	MyArray<int> a(5);
	a.begin();

	return 0;
}