#include <iostream>
#include <deque>
#include <stack>

int main()
{
	std::deque<int> deq = { 1,2,3 };
	deq.push_front(0);
	std::stack<int> stack;
	// stackû���ṩiterator����ֹ�ƻ����Ķ��ؽṹҪ��
	for (const auto& i: deq)
	{
		std::cout << i << std::endl;
	}
	return 0;
}