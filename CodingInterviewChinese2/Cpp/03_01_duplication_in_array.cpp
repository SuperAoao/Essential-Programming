// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
#include <iostream>


// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] >(length - 1))
		{
			return false;
		}
	}
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])// already existed, so we determin the dupulication
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}


// 测试代码
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == number)
			return true;
	}
	return false;
}
void test(char* testName, int array[], int length, int duplications[], int duplicationsLen, bool expectResult)
{
	printf("%s begins: \n", testName);
	int duplication = -1;
	bool testResult = duplicate(array, length, &duplication);

	if (expectResult == testResult)
	{
		if (expectResult)
		{
			if (contains(duplications, duplicationsLen, duplication))
				printf("Passed.\n");
			else
				printf("Failed. your duplication: %d is not contained in expect duplications\n"
					, duplication);
		}
		else
		{
			printf("Passed.\n");
		}
	}
	else
	{
		printf("Failed. Expect result: %d,  your result: %d\n",expectResult, testResult);
	}

}
// 测试用例1，随机
void test1()
{
	int numbers[] = { 3,6,3,2,1,0 };
	int duplications[] = { 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int)
		, duplications, sizeof(duplications) / sizeof(int), false);
}

// 测试用例2，无重复, 其中有大于n-1的非法数值
void test2()
{
	int numbers[] = { 2, 7, 1, 9 };
	int duplications[] = { -1 }; // not in use in the test function
	test("test2", numbers, sizeof(numbers) / sizeof(int)
		, duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test3()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("test3", numbers, 0
		, duplications, sizeof(duplications) / sizeof(int), false);
}

// 重复的数字是数组中最小的数字
void test4()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test5()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test6()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test7()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test8()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test9()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return 0;
}