#include <iostream>


int main()
{
    int i;
	while (std::cin >> i, !std::cin.eof())
	{
		if (std::cin.bad())
		{
			throw std::runtime_error("std::cin is corrupted.");
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "data format error, please try again." << std::endl;
			continue;
		}
		std::cout << i;
	}
	std::cout << "process finished." << std::endl;
	return 0;
}