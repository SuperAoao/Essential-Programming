#include <iostream>
// RTTI
// Run Time Type Identification

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
    GunV* pistol = new PistolV;
    // 使用typeid 子类和父类必须有虚函数，否则会出错
    std::cout << "typeid: " << typeid(pistol).name() << std::endl;
    // if (typeid(pistol).name() == "class PistolV") 经典错误，const char* == const char*，比较的是地址而不是内容
    PistolV* p = dynamic_cast<PistolV*>(pistol);
    if (p)
    {
        std::cout << "dynamic_cast: parent to child succeed" << std::endl;
    }
  
    return 0;
}