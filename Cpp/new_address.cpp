#include <iostream>
#include <vector>

int main() {
    // 假设已知内存地址为 address
    std::vector<int>* tempVec = new std::vector<int>(10, 1);
    // 访问并打印向量中的元素
    for (int i : *tempVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    void* address = static_cast<void*>(tempVec)/* 已知的内存地址 */;

    // 使用定位 new 运算符在指定地址构造一个 std::vector<int>
    std::vector<int>* vec = new(address) std::vector<int>(10,2);

    // 向向量中添加一些元素
    vec->push_back(10);
    vec->push_back(20);
    vec->push_back(30);

    // 访问并打印向量中的元素
    for (int i : *vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 不要忘记手动调用析构函数来销毁向量
    vec->~vector<int>();

    return 0;
}
