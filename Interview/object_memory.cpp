#include <iostream>
#include <iostream>
// 查看对象的内存分配情况
class Test
{
public:
    Test()
    {
        m_data = new char[1024*1024*1024];
    }
private:
    char* m_data;
};

int main()
{
    Test t;
    int i;
    std::cin >> i;
    return 0;
}