#pragma once
#include <iostream>

class Test
{
public:
	Test(int num);
	void print();
private:
	int m_num;
};

class Cat
{
public:
	Cat();
	void print();
private:
	Test* m_t;
};
extern Test* g_t;