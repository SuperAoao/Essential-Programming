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
	return 0;
}