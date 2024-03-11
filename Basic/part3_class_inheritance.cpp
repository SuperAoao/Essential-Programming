#include <iostream>
#include <thread>

int main()
{
    std::thread myThread([]() {
        std::cout << "Hello, world!" << std::endl;
        });
    myThread.join();
    std::thread myThread1([]() {
        for (int i = 0; i < 10000; i++)
        {
            std::cout << i << std::endl;
        }
        });
    // detach后，主线程结束后子线程虽然也会结束，但子线程的资源会被C++运行时库接管，避免问题
    myThread1.detach();
    return 0;
}