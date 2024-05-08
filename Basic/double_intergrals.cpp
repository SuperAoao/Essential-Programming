/*
* 
*/

#include <iostream>
#include <cmath>

// 被积函数
double f(double x, double y) {
    return x * y; // 例如计算 x * y 的二重积分
}

// 二重梯形法则计算二重积分
double double_trapezoidal_rule(double a, double b, double c, double d, int nx, int ny) {
    double hx = (b - a) / nx; // x 方向步长
    double hy = (d - c) / ny; // y 方向步长
    double sum = 0.0;

    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            double x0 = a + i * hx; // 当前子区间左边界的 x 值
            double x1 = a + (i + 1) * hx; // 当前子区间右边界的 x 值
            double y0 = c + j * hy; // 当前子区间下边界的 y 值
            double y1 = c + (j + 1) * hy; // 当前子区间上边界的 y 值

            // 计算当前子区间的面积，并乘以函数值
            sum += (f(x0, y0) + f(x1, y0) + f(x0, y1) + f(x1, y1)) / 4.0 * hx * hy;
        }
    }

    return sum;
}

int main() {
    double a = 0.0; // 积分下限
    double b = 1.0; // 积分上限
    double c = 0.0; // 积分下限
    double d = 1.0; // 积分上限
    int nx = 100; // x 方向的子区间数量
    int ny = 100; // y 方向的子区间数量

    double integral = double_trapezoidal_rule(a, b, c, d, nx, ny); // 计算二重积分
    std::cout << "Double integral of x * y from (" << a << ", " << b << ") to (" << c << ", " << d << ") is: " << integral << std::endl;

    return 0;
}
