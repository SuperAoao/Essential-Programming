#pragma once
#include <iostream>
#include "part1_c_extern_file1.h"

class Car
{
public:
	Car();
	void print();
private:
	Test* m_t;
};