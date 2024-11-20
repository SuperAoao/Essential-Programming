#include <cstdint>
#include <atomic>
#include <thread>
#include <cassert>
#include <iostream>

// int __cdecl hook_func() {
// }

//__stdcall 和 __cdecl 是两种不同的函数调用约定，它们影响了函数调用时参数的传递方式、堆栈的清理方式以及函数名修饰等方面。下面是它们的主要区别：
//
//参数传递方式：
//
//__stdcall：参数从右向左依次入栈，由被调用函数负责清理堆栈空间。
//__cdecl：参数从右向左依次入栈，由调用函数负责清理堆栈空间。
//堆栈的清理：
//
//__stdcall：被调用函数负责清理堆栈空间，因此在函数返回后，被调用函数会自动将其参数从堆栈中弹出。
//__cdecl：调用函数负责清理堆栈空间，因此在调用函数中，需要手动清理堆栈空间。
//函数名修饰：
//
//__stdcall：函数名不会进行修饰。
//__cdecl：函数名可能会进行修饰，以区分不同的函数。
//可移植性：
//
//__stdcall：通常用于 Windows 平台 API 函数，但不太适用于跨平台开发，因为其他操作系统（如 Linux、macOS）通常使用的是 __cdecl 或其他调用约定。
//__cdecl：在许多编译器和操作系统中都是默认的调用约定，因此具有较好的可移植性。
//一般来说，在 Windows 平台上，Windows API 函数通常使用 __stdcall 调用约定，而用户自定义的函数通常使用 __cdecl 调用约定。在跨平台开发中，建议使用默认的调用约定，以确保代码的可移植性。


/*
__cdecl ：（C DECLaration的缩写（declaration，声明）-C语言默认的函数调用方法）
是C DECLaration的缩写（declaration，声明），表示C语言默认的函数调用方法：所有参数从右到左依次入栈，这些参数由调用者清除，称为手动清栈。被调用函数不需要求调用者传递多少参数，调用者传递过多或者过少的参数，甚至完全不同的参数都不会产生编译阶段的错误。 　　

_stdcall ：（StandardCall的缩写，是C++的标准调用方式）
是StandardCall的缩写，是C++的标准调用方式：所有参数从右到左依次入栈，如果是调用类成员的话，最后一个入栈的是this指针。这些堆栈中的参数由被调用的函数在返回后清除，使用的指令是 retnX，X表示参数占用的字节数，CPU在ret之后自动弹出X个字节的堆栈空间，这些参数由被调用者清除称为自动清栈。函数在编译的时候就必须确定参数个数，并且调用者必须严格的控制参数的生成，不能多，不能少，否则返回后会出错。
————————————————

版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/Windgs_YF/article/details/109897203
*/

int __stdcall original_func(int a, float b) {
    return a + b;
}

int __cdecl hook_func_real(int a, float b) {
    return original_func(a, b);
}

using OriginFunc = decltype(original_func);

int main() {
    // 这种方式通过将 hook_func_real 转换为 OriginFunc* 类型的函数指针，然后通过该指针来调用函数。这种方式保留了原始函数的函数签名信息，并将其视为 OriginFunc 类型的函数，因此会使用 __stdcall 调用约定。
    std::cout <<  ((OriginFunc*)hook_func_real)(1, 2.0f) << std::endl;
    // 这种方式直接调用 hook_func_real 函数，没有经过任何函数指针的转换。由于 hook_func_real 函数的声明中使用了 __cdecl 调用约定，因此此调用方式也会使用 __cdecl 调用约定。
    std::cout << hook_func_real(3, 4.5) << std::endl;
    return 0;
}
