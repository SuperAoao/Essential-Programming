#include <iostream>
#include <set>
#include <map>
#include <string>

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

	for ( const auto& elem : intStringMap )
	{
		std::cout << elem.first << " " << elem.second << std::endl;
	}

	std::cout << "multimap" << std::endl;
	std::multimap<int, std::string> intStringMultiMap;
	intStringMultiMap.insert(std::pair<int, std::string>(10, "Hi"));
	intStringMultiMap.insert(std::pair<int, std::string>(10, "Wa"));
	intStringMultiMap.insert(std::pair<int, std::string>(5, "OK"));

	for (const auto& elem : intStringMultiMap)
	{
		std::cout << elem.first << " " << elem.second << std::endl;
	}
	return 0;
}