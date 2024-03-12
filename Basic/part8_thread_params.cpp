#include <iostream>
#include <thread>

void test(const int& i)
{
    std::cout << "test thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "&i: " << &i << std::endl;
}

int main()
{
    // 尽量不要使用隐式类型转换传参给子线程，因为构造是在子线程中
    // 子线程的引用传参默认是会经过一次拷贝的，所以地址不同，要想修改，需要使用std::ref
    std::cout << "main thread: " << std::this_thread::get_id() << std::endl;
    int i = 100;
    std::cout << "&i: " << &i << std::endl;
    std::thread testThread(test, i);
    testThread.join();
    return 0;
}