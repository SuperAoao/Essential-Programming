//https://zhuanlan.zhihu.com/p/394184676
#include <iostream>
#include <iostream>
using namespace std;

//这里加一个空模板函数是为了编译可以通过，否则编译期间调用printAmt<int>(int&)就会找不到可匹配的函数
//模板参数第一个类型实际上是用不到的，但是这里必须要加上，否则就是调用printAmt<>(int&)，模板实参为空，但是模板形参列表是不能为空的
template<class type>
void printAmt(int& iSumAge)
{
    return;
}

template<class type, int age0, int ... age>
void printAmt(int& iSumAge)
{
    iSumAge += age0;
    //这里sizeof ... (age)是计算形参包里的形参个数，返回类型是std::size_t，后续同理
    if ((sizeof ... (age)) > 0)
    {
        std::cout << "sizeof ...(age): " << sizeof ... (age) << std::endl;
        //这里的age...其实就是语法中的一种包展开，这个后续会具体说明
        printAmt<type, age...>(iSumAge);
    }
}


void xprintf() {}
template <typename T, typename... Targs>
void xprintf(T value, Targs... Fargs)
{
    std::cout << sizeof...(Fargs) << " " << value << std::endl;
    xprintf(Fargs...);
}

int main()
{
    int sumAge = 0;
    printAmt<int, 1, 2, 3, 4, 5, 6, 7, 8>(sumAge);
    cout << "the sum of age is " << sumAge << endl;
    xprintf("小明个人信息:", "小明", "男", 35, "程序员", 169.5);
    return 0;
}