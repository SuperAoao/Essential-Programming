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

int GetSize(int data[])
{
    return sizeof(data);
}
int main()
{
    std::cout << "sizeof Empty class: " << sizeof(EmptyClass) << std::endl;
    std::cout << "sizeof class with virtual function: " << sizeof(ClassWithVirtualFunc) << std::endl;

    int data1[] = { 1, 2, 3, 4, 5 };
    int size1 = sizeof(data1);

    int* data2 = data1;
    int size2 = sizeof(data2);

    int size3 = GetSize(data1);
    printf("%d, %d, %d", size1, size2, size3);
    return 0;
}