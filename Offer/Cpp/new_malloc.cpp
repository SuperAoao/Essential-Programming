#include <iostream>


int main()
{
    int a = 0;
    // unsigned int类型通常是32位的，可以表示的最大无符号整数是4294967295。
    // 因此，如果你尝试将100000000000赋值给unsigned int类型的变量，会导致溢出，这可能会导致意想不到的结果。
    // unsigned int GB_100 = 100000000000;
    uint64_t GB_100 = 100000000000;
    void* temp = malloc(GB_100);
    
    std::cin >> a;
    return 0;
}