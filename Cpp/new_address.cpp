#include <iostream>
#include <vector>

int main() {
    // ������֪�ڴ��ַΪ address
    std::vector<int>* tempVec = new std::vector<int>(10, 1);
    // ���ʲ���ӡ�����е�Ԫ��
    for (int i : *tempVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    void* address = static_cast<void*>(tempVec)/* ��֪���ڴ��ַ */;

    // ʹ�ö�λ new �������ָ����ַ����һ�� std::vector<int>
    std::vector<int>* vec = new(address) std::vector<int>(10,2);

    // �����������һЩԪ��
    vec->push_back(10);
    vec->push_back(20);
    vec->push_back(30);

    // ���ʲ���ӡ�����е�Ԫ��
    for (int i : *vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // ��Ҫ�����ֶ�����������������������
    vec->~vector<int>();

    return 0;
}
