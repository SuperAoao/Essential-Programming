#include "part1_c_extern_file1.h"

Test::Test(int num) :m_num(num)
{

}

void Test::print()
{
	std::cout << this << std::endl;
	std::cout << m_num << std::endl;
}



Cat::Cat()
{
	m_t = g_t;
}

void Cat::print()
{
	std::cout << "Cat: " << std::endl;
	m_t->print();
}
