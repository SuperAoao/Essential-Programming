#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

std::atomic<unsigned int> g_count_atomic = 0;
unsigned int g_count = 0;
std::mutex mutex_count;

unsigned int g_count_mute = 0;

void test()
{
    for (int i = 0; i < 10000000; i++)
    {
        g_count++;
        g_count_atomic++;
    }
}

void testWithLock()
{
    std::lock_guard<std::mutex> lockGuard(mutex_count);
    for (int i = 0; i < 10000000; i++)
    {
        g_count_mute++;
    }
}


int main()
{
    std::thread testThreadAlpha(test);
    std::thread testThreadBeta(test);
    testThreadAlpha.join();
    testThreadBeta.join();
    std::cout << "g_count: " << g_count << std::endl;
    std::cout << "g_count_atmoic: " << g_count_atomic << std::endl;

    {
        std::thread testThreadAlpha(testWithLock);
        std::thread testThreadBeta(testWithLock);
        testThreadAlpha.join();
        testThreadBeta.join();
        std::cout << "g_count_mute: " << g_count_mute << std::endl;
    }
    return 0;
}