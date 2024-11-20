// Reference.cpp: 定义应用程序的入口点。
//

#include "Reference.h"

using namespace std;

class A
{
public:
	A(int& num) :_num(num)
	{};
	void print()
	{
		std::cout << "A:_num = " <<  _num << std::endl;
	};
private:
	int _num;
};

class B
{
public:
	B(int& num) :_num(num)
	{};
	void print()
	{
		std::cout << "B:_num = " << _num << std::endl;
	};
private:
	int& _num;
};

int main()
{
	/*int num = 3;
	A a = A(num);
	B b = B(num);
	a.print();
	b.print();
	num = 1;
	a.print();
	b.print();*/
	int* num_ptr = new int(3);
	A a = A(*num_ptr);
	B b = B(*num_ptr);
	a.print();
	b.print();
	delete num_ptr;
	num_ptr = nullptr;
	a.print();
	b.print();
	cout << "Hello CMake." << endl;
	return 0;
}
