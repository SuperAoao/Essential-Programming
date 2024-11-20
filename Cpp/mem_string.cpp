#include <iostream>

void displayStringFromMemory(void* address, size_t size) {
    // 将内存地址转换为指向字符类型的指针
    char* charPtr = reinterpret_cast<char*>(address);

    // 创建一个字符串，并将内存中的数据复制到字符串中
    std::string str(charPtr, size);

    // 显示字符串
    std::cout << "String from memory: " << str << std::endl;
}

int main() {
    std::string str("Hello, world!");
    // 假设已知内存地址为 address，字符串大小为 size
    char* c_str = const_cast<char*>(str.c_str());
    void* address = reinterpret_cast<void*>(c_str)/* 已知的内存地址 */;
    size_t size = strlen(str.c_str())/* 已知的字符串大小 */;

    // 调用函数显示字符串内容
    displayStringFromMemory(address, size);

    return 0;
}
