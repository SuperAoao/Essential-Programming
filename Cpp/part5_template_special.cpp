#include <iostream>


template <typename T>
struct getType
{
    using type = T;
};

int main() {
    // 实例化 getType 结构体，并传入 double 作为模板参数
    getType<double> myType;

    // 使用嵌套类型别名 type 来获取传入的类型
    using MyType = typename getType<double>::type;

    // 定义指向 MyType 类型的指针
    MyType value = 3.14;
    MyType* ptr = &value;

    // 打印指针地址和值
    std::cout << "Pointer address: " << ptr << std::endl;
    std::cout << "Value pointed to: " << *ptr << std::endl;

    return 0;
}
