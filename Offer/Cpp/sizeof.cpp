#include <iostream>

class EmptyClass
{
    EmptyClass() = default;
    ~EmptyClass() = default;
};

class ClassWithVirtualFunc
{
    ClassWithVirtualFunc() = default;
    virtual ~ClassWithVirtualFunc() = default;
};
int main()
{
    std::cout << "sizeof Empty class: " << sizeof(EmptyClass) << std::endl;
    std::cout << "sizeof class with virtual function: " << sizeof(ClassWithVirtualFunc) << std::endl;
    return 0;
}