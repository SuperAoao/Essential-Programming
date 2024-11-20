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
    // ʹ��typeid ����͸���������麯������������
    std::cout << "typeid: " << typeid(pistol).name() << std::endl;
    // if (typeid(pistol).name() == "class PistolV") �������const char* == const char*���Ƚϵ��ǵ�ַ����������
    PistolV* p = dynamic_cast<PistolV*>(pistol);
    if (p)
    {
        std::cout << "dynamic_cast: parent to child succeed" << std::endl;
    }
  
    return 0;
}