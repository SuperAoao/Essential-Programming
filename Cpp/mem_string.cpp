#include <iostream>

void displayStringFromMemory(void* address, size_t size) {
    // ���ڴ��ַת��Ϊָ���ַ����͵�ָ��
    char* charPtr = reinterpret_cast<char*>(address);

    // ����һ���ַ����������ڴ��е����ݸ��Ƶ��ַ�����
    std::string str(charPtr, size);

    // ��ʾ�ַ���
    std::cout << "String from memory: " << str << std::endl;
}

int main() {
    std::string str("Hello, world!");
    // ������֪�ڴ��ַΪ address���ַ�����СΪ size
    char* c_str = const_cast<char*>(str.c_str());
    void* address = reinterpret_cast<void*>(c_str)/* ��֪���ڴ��ַ */;
    size_t size = strlen(str.c_str())/* ��֪���ַ�����С */;

    // ���ú�����ʾ�ַ�������
    displayStringFromMemory(address, size);

    return 0;
}
