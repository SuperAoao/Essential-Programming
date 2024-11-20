#include <iostream>
#include <thread>

void test(const int& i)
{
    std::cout << "test thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "&i: " << &i << std::endl;
}

int main()
{
    // ������Ҫʹ����ʽ����ת�����θ����̣߳���Ϊ�����������߳���
    // ���̵߳����ô���Ĭ���ǻᾭ��һ�ο����ģ����Ե�ַ��ͬ��Ҫ���޸ģ���Ҫʹ��std::ref
    std::cout << "main thread: " << std::this_thread::get_id() << std::endl;
    int i = 100;
    std::cout << "&i: " << &i << std::endl;
    std::thread testThread(test, i);
    testThread.join();
    return 0;
}