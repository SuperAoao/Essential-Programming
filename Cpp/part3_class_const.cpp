#include <iostream>

class Test
{
public:
    Test(const std::string& name, unsigned int age)
        : m_name(name)
        , m_age(age)
    {

    }
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

int main()
{
    Test t("123", 20);
    (t.*pf)();
    t.output();
    const Test t_const("t_const", 19);
    t_const.output();
    // ���������޸�
    //t_const.setAge(31);
    return 0;
}