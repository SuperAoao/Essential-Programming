#include <iostream>

int main()
{
    // left value: i 
    // right value 10
    int i = 10; 
    ++i = 20;
    // i++ returns a right value that can not be assigned
    // i++ = 30; 

    const int i_const = 100;
    // 左值引用只是对象别名，无法绑定常量对象
    //  int& ref = i_const; 
    const int& ref_const = i_const;
    // const引用可以引用const对象和右值
    const int& ref_right_value = (i_const + 1);

    // 右值引用
    int&& rref_i = 200;
    return 0;
}