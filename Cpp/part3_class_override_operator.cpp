#include <iostream>

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
    void operator()(int n)
    {
        std::cout << "operator()(int n): " << n << std::endl;
    }

private:
    std::string m_name;
    unsigned int m_age;
};


void (Test::* pf)() = &Test::output;

int main()
{
    Test t("123", 20);
    (t.*pf)();
    t.output();
    const Test t_const("t_const", 19);
    t_const.output();
    // ���������޸�
    //t_const.setAge(31);
    t(2);
    t.operator()(3);
    Test* t1 = new Test();

    return 0;
}