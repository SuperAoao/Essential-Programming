#include <iostream>

int main()
{
	// C++条件判断不支持连续比较
	double viewDis = 0.0;
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
	}
    return 0;
}