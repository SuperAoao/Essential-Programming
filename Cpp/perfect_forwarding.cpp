// Rvalues are

// temporary objects.
// objects without names.
// objects which have no address.

#include <iostream>

template<typename T>
void fun(T&& t)
{
    funA(std::forward<T>(t));
}

template<typename T>
void funA(T t)
{

}

int main()
{
    std::cout << "I am good at C++!";
    return 0;
}