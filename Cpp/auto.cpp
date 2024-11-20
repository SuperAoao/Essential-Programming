#include <iostream>

int main()
{
    const int a_const = 10;
    // a_const = 20;// 表达式必须是可修改的左值。 const提示编译器这个值不可修改，但它其实仍存储在变量区
    auto b = a_const; // 推断不包含const
    b = 1;
   
    std::cout << "b: " << b << std::endl;
    std::cout << "a: " << a_const << std::endl;
    
    auto& a_const_ref = a_const;
    //a_ref = 20; // 表达式必须是可修改的左值

    int a_var = 10;

    auto& a_var_ref = a_var;
    a_var_ref = 5;

    std::cout << "a_const_ref: " <<  a_const_ref << std::endl;
    std::cout << "a_const: " << a_const << std::endl;

    std::cout << "a_var_ref: " << a_var_ref << std::endl;
    std::cout << "a_var: " << a_var << std::endl;
    return 0;
}