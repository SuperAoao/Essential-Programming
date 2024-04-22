#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 1,2,3 };

    // assertion failed
    //! vec[10];


    try
    {
        // exception
        vec.at(10);
    }
    catch(const std::out_of_range& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    
    auto iter = vec.insert(vec.cbegin(), 100);
    std::cout << "distance: " << std::distance(vec.begin(), iter)  << std::endl;
    // 不扩张的最大容量
    std::cout << "capactiy: " << vec.capacity() << std::endl;
    // 最大容量
    std::cout << "max size: " << vec.max_size() << std::endl;

    vec.assign({ 4,5,6 });
    for (auto& i: vec)
    {
        std::cout << i << std::endl;
    }
}