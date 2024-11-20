#include <iostream>
#include <forward_list>

int main()
{
	// 排序更快
	std::forward_list<int> forwardList = { 1,2,3 };
	auto iter = forwardList.begin();
	// 不支持反向
	//--iter;
	// 没有尾端锚点
	// 只能往前放，可以想到如果要放在末尾太慢了
	forwardList.push_front(4);
	for (auto i: forwardList)
	{
		std::cout << i << std::endl;
	}

	
	return 0;
}