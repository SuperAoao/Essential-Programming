#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 1,2,3 };

    // assertion failed
    //vec[10];

    // exception
    try
    {
        vec.at(10);
    }
    catch(const std::out_of_range& exception)
    {
        std::cout << exception.what() << std::endl;
    }

    auto iter = vec.insert(vec.cbegin(), 100);
    std::cout << "distance: " << std::distance(vec.begin(), iter);
}