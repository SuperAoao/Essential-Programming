#include <iostream>
#include <thread>

void func()
{
    int a[64];
    std::cout << "stack memory addrees of a:" << &a << std::endl;
}

int main()
{
    std::thread threadA(func);
    std::thread threadB(func);
    threadA.join();
    threadB.join();

    std::cout << "-----stack memory address on main thread------" << std::endl;
    func();
    func();
    return 0;

}