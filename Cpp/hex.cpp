#include <iostream>
#include <iomanip> // 包含格式化输出所需的头文件

void displayCharInHex(char c) {
    // 使用 std::hex 操纵符以十六进制格式输出字符
    std::cout << "Character in hexadecimal: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) << std::endl;
}

int main() {
    // 假设已知字符为 c
    char c = 'a'/* 已知的字符 */;

    // 调用函数以十六进制格式显示字符
    displayCharInHex(c);

    return 0;
}
