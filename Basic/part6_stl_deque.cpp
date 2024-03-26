#include <iostream>
#include <deque>

int main()
{
	std::deque<int> deq = { 1,2,3 };
	deq.push_front(0);

	for (const auto& i: deq)
	{
		std::cout << i << std::endl;
	}
	return 0;
}