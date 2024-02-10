#include <cstdlib>
#include <iostream>
#include <string>
// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
class CMyString
{
public:
	CMyString(char* pData = nullptr) 
	{
		if (pData == nullptr)
		{
			m_pData = new char[1];
			m_pData[0] = '\0';
		}
		else
		{
			m_pData = new char[strlen(pData) + 1];
			strcpy(m_pData, pData);
		}
		
	};
	CMyString(const CMyString& str) 
	{ 
		int length = strlen(str.m_pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, str.m_pData);
	};
	~CMyString(void)
	{ 
		delete[] m_pData; 
		m_pData = nullptr;
	};

	char* getString()
	{
		return m_pData;
	}

	// write assginment operator function
	// junior
	//CMyString& operator =(const CMyString& str)
	//{
	//	if (this == &str)
	//	{
	//		return *this;
	//	}
	//	delete[] m_pData;
	//	m_pData = nullptr;

	//	m_pData = new char[strlen(str.m_pData) + 1];
	//	strcpy(m_pData, str.m_pData);

	//	return *this; // Very important
	//};
	// The experienced ones will consider exception safety.
	CMyString& operator =(const CMyString& str)
	{
		if (this != &str)
		{
			CMyString strTemp(str);
			// if mem is not enough, new will throws exception, at that moment we did not change this instance.
			char* pTemp = strTemp.m_pData;
			strTemp.m_pData = m_pData;
			m_pData = pTemp;
		}
	
		return *this; // Very important
	};
	
	void Print()
	{
		printf("%s", m_pData);
	}
private:
	char* m_pData;
};



// ====================测试代码====================
void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}