#include <iostream>

int main()
{
    int test_int = 30;
    /// const 在*左边，限制指针指向的内容
    const int* p_left = new int(10);
    p_left = &test_int; // 可以修改指针指向的地址
    // *p = 20; // 不可修改指针指向的内容
    // p_left = test_int;
    /// 另一种写法
    int const* p_left1 = new int(40);
    // *p_left1 = 20; // 表达式必须是可修改的左值
    p_left1 = &test_int;
     
    /// const 在*右边，限制指针的地址
    int* const p_right = new int(20);
    *p_right = 10;
    // p_right = &test_int; // 表达式必须是可修改的左值

    std::cout << "p_left: " << * p_left << std::endl;
    std::cout << "p_left1: " << *p_left1 << std::endl;
    std::cout << "p_right: " << *p_right << std::endl;
    return 0;
}