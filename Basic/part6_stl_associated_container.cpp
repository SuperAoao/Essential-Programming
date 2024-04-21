#include <iostream>
#include <set>
#include <map>
#include <string>

class Empty
{

};

int main()
{
	// 增删频繁实用
	// 元素位置和元素的值有关，和插入顺序无关
	std::cout << "set" << std::endl;
	// set 红黑树
	std::set<int> mySet = { 3,3,1,5 };
	for (const int i: mySet)
	{
		std::cout << i << std::endl;
	}
	// u must delete old values and insert elements with new values.
	
	auto setIter = mySet.begin();
	// 底层的RB_Tree使用了const限制，防止修改值
	//*setIter = 5;
	// set其实也是个container adaptor

	std::cout << "multiset" << std::endl;
	// 相同元素的值可以出现多次
	std::multiset<int> myMultiSet = { 3,3,1,5 };
	for (const int i : myMultiSet)
	{
		std::cout << i << std::endl;
	}

	// map 红黑树
	std::cout << "map" << std::endl;
	std::map<int, std::string> intStringMap;
	intStringMap.insert(std::pair<int, std::string>(10, "Hi"));
	intStringMap.insert(std::pair<int, std::string>(10, "Wa"));
	intStringMap.insert(std::pair<int, std::string>(5, "OK"));
	// 只有map可以使用[]，multimap都不行
	// 没有找到创建个默认值
	intStringMap[4];
	// 可以更新
	intStringMap[4] = "Replace";
	intStringMap[4] = "W";
	// 不会更新
	intStringMap.insert(std::pair<int, std::string>(4, "A"));

	for ( const auto& elem : intStringMap )
	{
		std::cout << elem.first << " " << elem.second << std::endl;
	}

	std::cout << "multimap" << std::endl;
	std::multimap<int, std::string> intStringMultiMap;
	intStringMultiMap.insert(std::pair<int, std::string>(10, "Hi"));
	intStringMultiMap.insert(std::pair<int, std::string>(10, "Wa"));
	intStringMultiMap.insert(std::pair<int, std::string>(5, "OK"));

	//intStringMultiMap[1];

	for (const auto& elem : intStringMultiMap)
	{
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	return 0;
}