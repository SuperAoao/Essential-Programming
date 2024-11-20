#include <iostream>

void funcA()
{
	double valA;
	std::cout << "valA address in funcA: " << &valA << std::endl;
}

void funcB()
{
	double valB;
	std::cout << "valB address in funcB: " << &valB << std::endl;
}

int main(int _argc, char** _argv)
{
	// mem address in stack, bottom is smaller
	double val0;
	double val1;
	printf(" %p\n %p\n", &val0, &val1);
	funcA();
	funcB();
	return 0;
}