#include <iostream>
#include <thread>
// ��̬��: �����ڱ���ʱ��ȷ���˵�ַ
// ��̬��: ����ʱȷ������Ѱ�ҵ�ַ�ķ���������ʱ�ž��������ĸ��������麯�����Ƕ�̬��
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
        // �������������������virtual���ǳ�������������ڴ�й¶����
        Gun* pistol = new Pistol;
        delete pistol;
    }
    {
        GunV* pistolv = new PistolV;
        delete pistolv;
    }
    return 0;
}