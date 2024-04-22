#include <iostream>

struct Data {
    int data1;
    int data2;
    constexpr Data(int a, int b)
        : data1(a), data2(b)
    {}
    // constexpr 限定不再严格！
    constexpr int getData1() const {
        return data1 + data2;
    }
    constexpr int getData2() const {
        return data1 | data2;
    }

};

int main() {
    constexpr Data data(1, 2);
    constexpr auto a = data.getData1(); // 编译期常量，没有函数调用过程和开销
    auto b = data.getData2(); // 有函数调用过程和开销
    std::cout << "data.getData1() : " << a << std::endl;
    std::cout << "data.getData2() : " << b << std::endl;
    // 变量定义时带有constexpr，不允许修改
    //! data.data1 = 2; 
    return 0;
}