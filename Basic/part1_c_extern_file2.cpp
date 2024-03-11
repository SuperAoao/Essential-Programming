
#include "part1_c_extern_file2.h"
extern Test* g_t = new Test(2);

Car::Car()
{
	m_t = g_t;
}

void Car::print()
{
	std::cout << "Car: " << std::endl;
	m_t->print();
}

