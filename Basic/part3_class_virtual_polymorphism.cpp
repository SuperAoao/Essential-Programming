#include <iostream>
#include <thread>
// 静态绑定: 函数在编译时就确定了地址
// 动态绑定: 编译时确定函数寻找地址的方法，运行时才决定调用哪个函数。虚函数就是动态绑定
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
};

class Pistol : public Gun
{
public:
    Pistol()
    {
    };
    ~Pistol()
    {
        std::cout << "Pistol deconstruct" << std::endl;
    }
};

class GunV
{
public:
    GunV()
    {

    };
    virtual ~GunV()
    {
        std::cout << "GunV deconstruct" << std::endl;
    }
};

class PistolV : public GunV
{
public:
    PistolV()
    {
    };
     virtual ~PistolV()
    {
        std::cout << "PistolV deconstruct" << std::endl;
    }
};

int main()
{
    {
        // 父类析构函数如果不是virtual，非常容易造成子类内存泄露问题
        Gun* pistol = new Pistol;
        delete pistol;
    }
    {
        GunV* pistolv = new PistolV;
        delete pistolv;
    }
    return 0;
}