#include <iostream>
#include <iomanip> // ������ʽ����������ͷ�ļ�

void displayCharInHex(char c) {
    // ʹ�� std::hex ���ݷ���ʮ�����Ƹ�ʽ����ַ�
    std::cout << "Character in hexadecimal: 0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) << std::endl;
}

int main() {
    // ������֪�ַ�Ϊ c
    char c = 'a'/* ��֪���ַ� */;

    // ���ú�����ʮ�����Ƹ�ʽ��ʾ�ַ�
    displayCharInHex(c);

    return 0;
}
