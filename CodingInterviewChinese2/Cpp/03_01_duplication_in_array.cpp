// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��
#include <iostream>


// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
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


// ���Դ���
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
// ��������1�����
void test1()
{
	int numbers[] = { 3,6,3,2,1,0 };
	int duplications[] = { 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int)
		, duplications, sizeof(duplications) / sizeof(int), false);
}

// ��������2�����ظ�, �����д���n-1�ķǷ���ֵ
void test2()
{
	int numbers[] = { 2, 7, 1, 9 };
	int duplications[] = { -1 }; // not in use in the test function
	test("test2", numbers, sizeof(numbers) / sizeof(int)
		, duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
void test3()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("test3", numbers, 0
		, duplications, sizeof(duplications) / sizeof(int), false);
}

// �ظ�����������������С������
void test4()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test5()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test6()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test7()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test8()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
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