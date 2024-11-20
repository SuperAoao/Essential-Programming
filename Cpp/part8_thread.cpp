#include <iostream>
// OOP�������ԣ���װ���̳кͶ�̬
class Test
{
public:
    Test() = default;
    Test(const Test& t) = default;
    Test& operator=(const Test& t) = delete;
    ~Test() = default;
    // C++11 ��ǰ������Ĭ�����ɵĺ�����ֻ�ܷ���private������ֻ����������
    Test(const std::string& name, unsigned int age) : m_name(name), m_age(age)
    {

    };
    // ����output
    void output() const
    {
        // �����ڳ���Ա�����������ͨ��Ա����������const���ƻ��к���
        //setAge(31);
        std::cout << "const function" << std::endl;
        std::cout << this->m_name << std::endl;
        std::cout << this->m_age << std::endl;
    }
    void output()
    {
        //setAge(31);
        std::cout << "non const function " << std::endl;
        std::cout << this->m_name << std::endl;
        std::cout << this->m_age << std::endl;
    }
    void setAge(int age)
    {
        m_age = age;
    }
private:
    std::string m_name;
    unsigned int m_age;
};


void (Test::* pf)() = &Test::output;

class Car
{
public:
    Car() {
        std::cout << "Car()" << std::endl;
    };
    ~Car()
    {
        std::cout << "~Car()" << std::endl;
    }
};
class SportsCar : public Car
{
public:
    SportsCar() {
        std::cout << "SportsCar()" << std::endl;
    }
    ~SportsCar()
    {
        std::cout << "~SportsCar()" << std::endl;
    }
};


int main()
{
    Test t("123", 20);
    (t.*pf)();
    t.output();
    const Test t_const("t_const", 19);
    t_const.output();
    // ���������޸�
    //t_const.setAge(31);

    SportsCar sportsCar;
    return 0;
}