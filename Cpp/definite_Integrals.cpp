/*
* In this example we use trapezoidal rule to calculate definite integrals
*/
#include <iostream>
#include <cmath>

// 被积函数
double f(double x) {
    return x * x; // 例如计算 x^2 的积分
}

// 梯形法则计算定积分
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n; // 计算步长
    double sum = (f(a) + f(b)) / 2.0; // 第一个和最后一个点的函数值求中值
    for (int i = 1; i < n; ++i) {
        double x = a + i * h; // 计算当前点的 x 值
        sum += f(x); // 加上当前点的函数值
    }
    return sum * h; // 返回积分值
}

int main() {
    double a = 0.0; // 积分下限
    double b = 1.0; // 积分上限
    int n = 10000; // 划分的子区间数量，值越大，结果越精确

    double integral = trapezoidal_rule(a, b, n); // 计算定积分
    std::cout << "Integral of x^2 from " << a << " to " << b << " is: " << integral << std::endl;

    return 0;
}