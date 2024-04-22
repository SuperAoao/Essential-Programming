#include <iostream>
#include <cstdint>
#include <bitset>

// 定义一个union
union MyUnion {
	int i;
	float f;
	char c;
};

struct Float {
	union {
		struct {
			uint32_t frac : 23; // 指定宽度
			uint32_t exp : 8;
			uint32_t sign : 1;
		};
		float val;
	};
	Float()
	{
		val = 0.0;
	}
};
int main()
{
	// C++条件判断不支持连续比较
	/*double viewDis = 0.0;
	std::cin >> viewDis;
	std::cout << "viewDis : " << viewDis << std::endl;
	if (0.0 < viewDis < 2000.0)
	{
		std::cout << "0.0 < viewDis < 2000.0" << std::endl;
	}
	else if (2000 <= viewDis < 5000)
	{
		std::cout << "2000 <= viewDis < 5000" << std::endl;
	}
	else if (5000 <= viewDis < 10000)
	{
		std::cout << "5000 <= viewDis < 10000" << std::endl;
	}
	else if (10000 <= viewDis < 20000)
	{
		std::cout << "10000 <= viewDis < 20000" << std::endl;
	}

	if (viewDis > 0.0 && viewDis < 2000.0)
	{
		std::cout << "0.0 < viewDis < 2000.0" << std::endl;
	}
	else if (viewDis >= 2000.0 && viewDis < 5000.0)
	{
		std::cout << "2000 <= viewDis < 5000" << std::endl;
	}
	else if (viewDis >= 5000.0 && viewDis < 10000.0)
	{
		std::cout << "5000 <= viewDis < 10000" << std::endl;
	}
	else if (viewDis >= 10000.0 && viewDis < 20000.0)
	{
		std::cout << "10000 <= viewDis < 20000" << std::endl;
	}*/

	// 创建一个union变量
	MyUnion u;

	// 分配内存给union的不同成员
	u.i = 10;
	std::cout << "Value of integer member: " << u.i << std::endl;

	u.f = 3.14f;
	std::cout << "Value of float member: " << u.f << std::endl;

	u.c = 'A';
	std::cout << "Value of char member: " << u.c << std::endl;

	// 同一时刻只能访问一个成员的值，因为它们共享内存
	std::cout << "Value of integer member after assigning char: " << u.i << std::endl;

	uint32_t varUint32 = 0;
	std::cout << "sizeof(uint32_t): " << sizeof(varUint32) << std::endl;
	int varInt = 0;
	std::cout << "sizeof(int): " << sizeof(varInt) << std::endl;
	long varLong = 0;
	std::cout << "sizeof(long): " << sizeof(varLong) << std::endl;

	// 符号取反
	// 一个带符号的32位整数，表示的是一个负数。在计算机中，负数通常使用补码表示法。
	// 要将补码转换为十进制，首先要确定该数的符号位。在补码表示法中，最高位为符号位，0表示正数，1表示负数。
	// 给定的二进制数最高位是1，所以它是一个负数。
	// 接下来，我们需要计算其补码。补码的计算方式是将原码取反，然后加1。
	int32_t a = 5;
	uint32_t b = a;
	b = b - 1;
	b = ~b;
	a = b;
	printf("a == %d\n", a);
	std::cout << "a == " << std::bitset<sizeof(a) * 8>(a) << std::endl;

	std::cout << "IEEE754" << std::endl;
	// sign(1)
	// exp(8)
	// frac(23)

	// e.g
	// 4.333
	// sign: 0 
	// binary: 4 = 100
	// binary: 0.333 = 01010101010101010101010
	// combined-binary:100.01010101010101010101010
	// 1.0001010101010101010101010
	// frac:0b00010101010101010101010

	// >>2 向右移动两位 exp:2
	// exp: 2 + 127 = 129

	//uint32_t fval = 0b0 1000 0001 00010101010101010101010;
	uint32_t fval = 0b01000000100010101010101010101010;
	std::cout << "uint32_t repsents float: " << *(float*)(&fval) << std::endl;

	Float f_union;
	f_union.frac = 0b00010101010101010101010;
	f_union.exp = 129;
	f_union.sign = 0;
	std::cout << "f_union repsents float: " << f_union.val << std::endl;

	uint32_t littleEndian_test_val = 1;
	
	/* 十进制小数转二进制
	// 0.333*2 = 0.666 -> 0
	// 0.666*2 = 1.332 -> 1
	// 0.332*2 = 0.664 -> 0
	// 0.664*2 = 1.328 -> 1
	// .
	// .
	// .
	*/
    return 0;
}