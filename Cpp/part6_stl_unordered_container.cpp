#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main()
{
	// ��ϣ,�޸Ĳ��ҿ�
	std::unordered_set<int> unorderedSet = { 4,1,2 };
	for (const int& i: unorderedSet)
	{
		std::cout << i << std::endl;
	}
	std::cout << "unorderedSet.bucket_count(): " <<unorderedSet.bucket_count() << std::endl;
	return 0;
}