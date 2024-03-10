#include <iostream>

class Test
{
public:
    Test(int age) : m_age(age) {};
    // 重载一元运算符++， 注意运算符的元数是不可更改的
    void operator++() { m_age++; };

    /*void operator++(int temp) { m_age += temp; };*/
    // 重载二元运算符=
    Test& operator=(const Test& t)
    {
        if (this == &t)
        {
            return *this;
        }
        m_age = t.m_age;
        return *this;
    }
    friend std::ostream& operator<< (std::ostream& os, const Test& t)
    {
        os << t.m_age << std::endl;
        return os;
    }
    void output()
    {
        std::cout << m_age << std::endl;
    }
private:
    unsigned int m_age;
};



int main()
{
    Test t(0);
    t.output();
    ++t;
    t.output();
    std::cout << t;
    return 0;
}