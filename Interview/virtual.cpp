#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A is created." << std::endl;
    }
    ~A()
    {
        std::cout << "A is deleted." << std::endl;
    }
    virtual void Fun(int number)
    {
        int numberA = number++;
        std::cout << "Func A:" << number << std::endl;
        std::cout << "Func A:" << numberA << std::endl;
        std::cout << "Func A:" << ++numberA << std::endl;
    }
};

class B : public A
{
public:
    B()
    {
        std::cout << "B is created." << std::endl;
    }
    ~B()
    {
        std::cout << "B is deleted." << std::endl;
    }
    void Fun(int number)
    {
        int numberB = number++;
        std::cout << "Fun A:" << number <<  std::endl;
        std::cout << "Fun B:" << numberB << std::endl;
        std::cout << "Fun B:" << ++numberB << std::endl;
    }
};



int main()
{
    A* pA = new B();
    pA->Fun(10);
    delete pA;

    return 0;
}

// Output
//A is created.
//B is created.
//Fun A : 11
//Fun B : 10
//Fun B : 11
//A is deleted.

// 因为A作为基类析构函数不是虚函数