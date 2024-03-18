#include "part5_template_class.hpp"
#include <vector>
#include <type_traits>

int main()
{
	std::initializer_list<int> list = { 1,2,3,4,5 };
	std::vector<int> vec(list);

	// ›Õ»°ºº ı
	int i1 = 10;
	int i2 = 20;
	std::initializer_list<int*> list_pointer = { &i1, &i2 };


	MyArray<int> a(5);
	a.begin();

	return 0;
}