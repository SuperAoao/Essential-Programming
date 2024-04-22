#include <stdio.h>
#include <iostream>
#include <bitset>

void f(unsigned char v)
{
    char c = v;
    unsigned char uc = v;
    unsigned int a = c, b = uc;
    int i = c, j = uc;

    printf("----------------\n");
    std::cout << "binary c: " << std::bitset<8>(c) << std::endl;
    printf("%%c: %c, %c\n", c, uc);
    printf("%%X: %X, %X\n", c, uc);
    std::cout << "binary unsigned uc: " << std::bitset<8>(uc) << std::endl;
    printf("%%u: %u, %u\n", a, b);
    printf("%%d: %d, %d\n", i, j);
}


int main(int argc, char* argv[])
{
    f(0x80);
    f(0x7F);
    return 0;
}