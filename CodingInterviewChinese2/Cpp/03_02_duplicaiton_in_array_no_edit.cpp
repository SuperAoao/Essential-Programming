/*在一个长度为n+1额数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字是重复的。
请找出数组中任意一个重复的数字，但不能修改输入的数组。例如，如果输入长度为8的数组{2，3，5，4，3，2，6，7}，
那么对应的输出是重复的数字2或3*/
#include <iostream>
#include <vector>

// space complexity O(n)
uint64_t getDuplicationInArray(const std::vector<uint64_t>& vec)
{
    unsigned int ret = -1;
    std::vector<uint64_t> temp;
    temp.reserve(vec.size());
    temp.assign(vec.size(), 0);
    for (const auto&num: vec)
    {
        if (temp[num] == 0)
        {
            temp[num] = num;
        }
        else
        {
            ret = num;
            return ret;
        }
    }

    return ret;
}

void test1()
{
    std::vector<uint64_t> a = {2,3,5,4,3,2,6,7};
    int testVal = getDuplicationInArray(a);
    if (testVal == 2 || testVal == 3)
    {
       std::cout << "test1 passed." << std::endl;
    }

    else
    {
        std::cout << "test1 failed." << std::endl;
    }
    
}

void test2()
{

}

int main()
{
    test1();
    return 0;
}