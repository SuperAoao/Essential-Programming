#include <iostream>
// OOP三大特性：封装、继承和多态
class Test
{
public:
    Test() = default;
    Test(const Test& t) = default;
    Test& operator=(const Test& t) = delete;
    ~Test() = default;
    // C++11 以前不想用默认生成的函数，只能放在private，或者只声明不定义
    Test(const std::string& name, unsigned int age) : m_name(name), m_age(age)
    {

    };
    // 重载output
    void output() const
    {
        // 不能在常成员函数里调用普通成员函数，否则const限制还有何用
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
    // 常对象不能修改
    //t_const.setAge(31);
    return 0;
}