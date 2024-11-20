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
    // detach�����߳̽��������߳���ȻҲ������������̵߳���Դ�ᱻC++����ʱ��ӹܣ���������
    myThread1.detach();
    return 0;
}