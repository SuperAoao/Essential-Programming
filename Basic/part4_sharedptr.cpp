#include <iostream>


int main()
{
	std::shared_ptr<int> s1 = std::make_shared<int>(20);
	std::cout << "s1: " << s1 << std::endl;
	std::cout << s1.unique() << std::endl;
	std::cout << s1.use_count() << std::endl;
	return 0;
}
