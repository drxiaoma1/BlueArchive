#include <iostream>
#include "Matrix.h"
int main() {
    int m, n;
    std::cin >> m >> n;  // 矩阵维度
    Matrix m1(m, n), m2(m, n), m3(n, m);  // 创建三个矩阵
    std::cin >> m1 >> m2 >> m3;
    std::cout << m1 << std::endl << m2 << std::endl << m3 << std::endl;
    std::cout << m1 + m2 << std::endl << m1 - m2 << std::endl << m1 * (!m2) << std::endl << m1 * m3 << std::endl;
    int i, j;  // 要取的行数和列数
    std::cin >> i >> j;
    std::cout << m1[i] << std::endl << m3(j) << std::endl << m1[i] * m3(j) << std::endl;
    std::cout << int(m2[i](j)) << std::endl;  // 将m2矩阵的第i行第j列转换为int类型的值并输出
    return 0;
}