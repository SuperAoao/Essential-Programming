//https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
#include <iostream>
using namespace std;
class Test {
    int* arr{ nullptr };
public:
    Test() :arr(new int[5000] {1, 2, 3, 4})
    {
        cout << "default constructor" << endl;
    }
    Test(const Test& t)
    {
        cout << "copy constructor" << endl;
        if (arr == nullptr)
        {
            arr = new int[5000];
        }
        memcpy(arr, t.arr, 5000 * sizeof(int));
    }
    ~Test() {
        cout << "destructor" << endl;
        delete[] arr;
    }
};

void printRValue(int&& i )
{
    std::cout << "i: " << std::endl;
    std::cout << "address of i: " << &i << std::endl;
}

int main()
{
    // left value: i 
    // right value 10
    int i = 10; 
    
    // ++i返回左值
    ++i = 20;
    // 无法将右值引用绑定到左值
    //int&& rref_i = i;

    // 使用move函数
    int&& rref_i = std::move(i);

    Test t;
    Test t1 = t;
    std::cout << "123" << std::endl;
    printRValue(10);
    return 0;
}