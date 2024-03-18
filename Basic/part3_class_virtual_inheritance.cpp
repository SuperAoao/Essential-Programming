#include <iostream>
#include <thread>
// 菱形继承
// 虚继承表，偏移值相同的变量只继承一份
class Gun
{
public:
    Gun()
    {

    };
    ~Gun()
    {
        std::cout << "Gun deconstruct" << std::endl;
    }
    int i = 10;
};

class AK : virtual public Gun
{
public:
    AK()
    {
    };
    ~AK()
    {
        std::cout << "AK deconstruct" << std::endl;
    }
};

class M4: virtual public Gun
{
public:
    M4()
    {

    };
    virtual ~M4()
    {
        std::cout << "M4 deconstruct" << std::endl;
    }
};

class AKM4 : public AK, public M4
{
public:
    AKM4()
    {
    };
     virtual ~AKM4()
    {
        std::cout << "AKM4  deconstruct" << std::endl;
    }
};

int main()
{
    {
        // 父类析构函数如果不是virtual，非常容易造成子类内存泄露问题
        AKM4* gun = new AKM4;
        std::cout << gun->i << std::endl;
    }

    return 0;
}