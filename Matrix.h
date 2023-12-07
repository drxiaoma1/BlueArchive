#ifndef Q3_MATRIX_H
#define Q3_MATRIX_H

#include <iostream>

class Matrix {
// 请在此声明输入输出函数，即对运算符<<和>>重载的友元函数
    friend std::ostream & operator << (std::ostream &, const Matrix &);
    friend std::istream & operator >> (std::istream &, Matrix &);

private:
    int ** data;
    const unsigned row, column;

public:
    Matrix(unsigned, unsigned);
    ~Matrix();

    // 请在此声明=，+，-，*的运算符重载函数
    Matrix operator + (const Matrix &) const;
    Matrix operator - (const Matrix &) const;
    Matrix operator * (const Matrix &) const;
    Matrix & operator = (const Matrix &) ;

    Matrix operator ! () const;  // 转置运算

    Matrix operator [] (unsigned) const;  // 取矩阵的第i行
    Matrix operator () (unsigned) const;  // 取矩阵的第j列

    explicit operator int () const;  // 矩阵维度为1*1时可以强制类型转换
};


#endif //Q3_MATRIX_H
