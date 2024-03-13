//https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
#include <iostream>
using namespace std;
class Test {
    int m_i = 10;
public:
    Test(const int i ) :m_i(i)
    {
        std::cout << "m_i: " << m_i << std::endl;
        m_i = 30;
        std::cout << "m_i: " << m_i << std::endl;
    }

};


int main()
{
    Test t(20);
    return 0;
}

//成员变量在使用初始化列表初始化时，与构造函数中初始化成员列表的顺序无关，只与定义成员变量的顺序有关。
//如果不使用初始化列表初始化，在构造函数内初始化时，此时与成员变量在构造函数中的位置有关。
//类中 const 成员常量必须在构造函数初始化列表中初始化。
//类中 static 成员变量，只能在类外初始化(同一类的所有实例共享静态成员变量)。