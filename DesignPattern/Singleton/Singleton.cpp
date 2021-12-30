// Singleton.cpp: 定义应用程序的入口点。
//

#include "Singleton.h"
#include <mutex>

#include <thread>

using namespace std;

// 懒汉式（非线程安全)
class LazySingleton
{
public:
    static LazySingleton* GetInstance()
    {
        if (m_pInstance == NULL)
            m_pInstance = new LazySingleton();
        return m_pInstance;
    }
private:
    LazySingleton() {};
    static LazySingleton* m_pInstance;
};


// 饿汉式(线程安全)
// 反对观点:因为静态的局部变量是在调用的时候分配到静态存储区，所以在编译的时候没有分配

class HungrySingleton
{
private:
    HungrySingleton()
    {
        std::cout << "enter non-thread-safe HungrySingletion Constructor" << std::endl;
    }
public:
    static HungrySingleton* GetInstance()
    {
        static HungrySingleton instance;
        return &instance;
    }
};

// 饿汉式（线程安全)
class SafeHungrySingleton
{
private:
    SafeHungrySingleton();
    ~SafeHungrySingleton();
    static SafeHungrySingleton _m;
public:
    static SafeHungrySingleton& GetInstance();
 
};
SafeHungrySingleton SafeHungrySingleton::_m;
SafeHungrySingleton::SafeHungrySingleton()
{
    std::cout << "enter safe HungrySingletion Constructor" << std::endl;
}
SafeHungrySingleton::~SafeHungrySingleton()
{
    std::cout << "enter safe HungrySingletion Destructor" << std::endl;
}
SafeHungrySingleton& SafeHungrySingleton::GetInstance()
{
    return _m;
}

int main()
{
	cout << "Hello CMake." << endl;
    //HungrySingleton::GetInstance();
	return 0;
}
