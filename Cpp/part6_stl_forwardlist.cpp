#include <iostream>
#include <forward_list>

int main()
{
	// �������
	std::forward_list<int> forwardList = { 1,2,3 };
	auto iter = forwardList.begin();
	// ��֧�ַ���
	//--iter;
	// û��β��ê��
	// ֻ����ǰ�ţ������뵽���Ҫ����ĩβ̫����
	forwardList.push_front(4);
	for (auto i: forwardList)
	{
		std::cout << i << std::endl;
	}

	
	return 0;
}