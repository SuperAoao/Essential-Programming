#include <iostream>

class CSingleton
{
public:
    static CSingleton& Instance()
    {
        static CSingleton s_instance;
        return s_instance;
    }
private:
    CSingleton() = default;
    ~CSingleton() = default;
    CSingleton(const CSingleton&) = delete;
    CSingleton& operator=(const CSingleton&) = delete;
    
};

int main()
{
    std::cout << &CSingleton::Instance() << std::endl;
     std::cout << &CSingleton::Instance() << std::endl;
    return 0;
}