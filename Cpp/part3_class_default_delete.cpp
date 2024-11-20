#include <iostream>

class Test
{
public:
    Test(int age) : m_age(age) {};
    // ����һԪ�����++�� ע���������Ԫ���ǲ��ɸ��ĵ�
    void operator++() { m_age++; };

    /*void operator++(int temp) { m_age += temp; };*/
    // ���ض�Ԫ�����=
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