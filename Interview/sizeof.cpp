#include <iostream>

char* g_str = "Hello";

int main()
{
    std::cout << "sizeof(g_str): " << sizeof(g_str) << std::endl;
    std::cout << "sizeof(*g_str): " << sizeof(*g_str) << std::endl;
    std::cout << "strlen(g_str): " << strlen(g_str) << std::endl;
    return 0;
}