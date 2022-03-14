/*****************************************************************//**
 * \file   TimeComplexity.cpp
 * \brief  时间复杂度往往也和输入有关
 * 
 * \author 210507
 * \date   March 2022
 *********************************************************************/

#include <iostream>
#include <chrono>
void computeCaseOne()
{
	int val = 1;
	for (int i = 1; i < 10000; i++)
	{
		// 加减法运算耗时少，与乘除相比可忽略不计
		val = val + 2 + pow(val, i);
	}
}

void computeCaseTwo()
{
	int val = 1;
	for (int i = 1; i < 10000; i++)
	{
		// 加减法运算耗时少，与乘除相比可忽略不计
		val = val * 2 + pow(val, i);
	}
}
void computeCaseThree()
{
	int val = 1;
	for (int i = 1; i < 10000; i++)
	{
		// 实际上这个算法耗时少，难道是硬件优化?
		val = val * 2 * pow(val, i);
	}
}
int main()
{
	auto time_before = std::chrono::steady_clock::now();
	computeCaseOne();
	auto time_after1 = std::chrono::steady_clock::now();
	computeCaseTwo();
	auto time_after2 = std::chrono::steady_clock::now();
	computeCaseThree();
	auto time_after3 = std::chrono::steady_clock::now();
	auto time_used1 = time_after1 - time_before;
	auto time_used2 = time_after2 - time_after1;
	auto time_used3 = time_after3 - time_after2;
	std::cout << "案例1耗时" << time_used1.count() << std::endl;
	std::cout << "案例2耗时" << time_used2.count() << std::endl;
	std::cout << "案例3耗时" << time_used3.count() << std::endl;
    std::cout << "Hello World!\n";
}
