#include <iostream>
#include <deque>
#include <stack>

int main()
{
	std::deque<int> deq = { 1,2,3 };
	deq.push_front(0);
	std::stack<int> stack;
	// stack没有提供iterator，防止破坏它的独特结构要求
	for (const auto& i: deq)
	{
		std::cout << i << std::endl;
	}
	return 0;
}