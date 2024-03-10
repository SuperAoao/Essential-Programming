#include <iostream>
#include <functional>

// 1. 函数
void printInt(int i)
{
    std::cout << "function printInt is called: " << std::endl;
    std::cout << i << std::endl;
}

using pf = void(*)(int);

// 2. 仿函数
class Test
{
public:
    void operator()(int t)
    {
        std::cout << "operator()(int t)" << std::endl;
        std::cout << t << std::endl;
    }
};

void customFuction(pf f, int i)
{
    f(i);
}

using pf_lambda = std::function<void(int)>;

void customFunctionSupportCapture(pf_lambda lambda, int i)
{
    lambda(i);
}

int main()
{
    customFuction(printInt, 20);
    Test t;
    t(30);
    // 3. lambda 表达式
    int val = 40;
    auto lambda = [val](double dTest)->int {
        std::cout << val << std::endl;
        std::cout << dTest << std::endl;
        return 1;
        }(300.0);

        // 不支持lambda捕获
        /*customFuction([val](int i) {
            std::cout << val << std::endl; std::cout << i << std::endl;
            }, 30);*/
        customFunctionSupportCapture([val](int i) {
            std::cout << val << std::endl; 
            std::cout << i << std::endl; 
            std::cout << "lambda" << std::endl;
            }, 30);
    return 0;
}