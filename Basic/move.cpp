#include <iostream>

int main()
{
    // left value: i 
    // right value 10
    int i = 10; 
    ++i = 20;
    // 无法将右值引用绑定到左值
    //int&& rref_i = i;

    // 使用move函数
    int&& rref_i = std::move(i);
    return 0;
}