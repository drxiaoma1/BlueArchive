//
// Created by mmk20 on 2023/12/7.
//
//class Matrix {
//// 请在此声明输入输出函数，即对运算符<<和>>重载的友元函数
//    friend std::ostream & operator << (std::ostream &, const Matrix &);
//    friend std::istream & operator >> (std::istream &, Matrix &);
//
//private:
//    int ** data;
//    const unsigned row, column;
//
//public:
//    Matrix(unsigned, unsigned);
//    ~Matrix();
//
//    // 请在此声明=，+，-，*的运算符重载函数
//    Matrix operator + (const Matrix &) const;
//    Matrix operator - (const Matrix &) const;
//    Matrix operator * (const Matrix &) const;
//
//    Matrix operator ! () const;  // 转置运算
//
//    Matrix operator [] (unsigned) const;  // 取矩阵的第i行
//    Matrix operator () (unsigned) const;  // 取矩阵的第j列
//
//    explicit operator int () const;  // 矩阵维度为1*1时可以强制类型转换
//
#include "iostream"
#include "Matrix.h"
using namespace std;
Matrix::Matrix(unsigned int m, unsigned int n):row(m),column(n)
{
    data=new int *[row];
    for(int i=0;i<row;i++)
        data[i]=new int [column];
}
std::ostream & operator << (std::ostream &os, const Matrix &a)
{
    for(int i=0;i<a.row;i++) {
        for (int j = 0; j < a.column; j++)
            os << a.data[i][j] << ' ';
        os<<endl;
    }
    return os;
}
std::istream & operator >> (std::istream &is, Matrix &a){
    for(int i=0;i<a.row;i++)
        for(int j=0;j<a.column;j++){
            is>>a.data[i][j];
        }
    return is;
}
Matrix::~Matrix()
{
    for (int i = 0; i < row; ++i) {
        delete [] data[i];
    }
    delete [] data;
}
Matrix Matrix::operator + (const Matrix &obj) const
{
    Matrix tmp(obj.row,obj.column);
    for(int i=0;i<obj.row;i++)
        for(int j=0;j<obj.column;j++)
            tmp.data[i][j]=data[i][j]+obj.data[i][j];
    return tmp;
}
Matrix Matrix::operator - (const Matrix &obj) const
{
    Matrix tmp(obj.row,obj.column);
    for(int i=0;i<obj.row;i++)
        for(int j=0;j<obj.column;j++)
            tmp.data[i][j]=data[i][j]-obj.data[i][j];
    return tmp;
}
Matrix Matrix::operator * (const Matrix &obj) const
{
    Matrix tmp(row,obj.column);
    for(int i=0;i<row;i++)
        for(int j=0;j<obj.column;j++)
        {
            tmp.data[i][j]=0;
        }
    for(int i=0;i<row;i++)
        for(int j=0;j<obj.column;j++)
        {
            tmp.data[i][j]+=data[i][j]*obj.data[j][i];
        }
    return tmp;
}
Matrix & Matrix::operator = (const Matrix &obj)
{
    if(this==&obj)return *this;
    for(int i=0;i<obj.row;i++)
        for(int j=0;j<obj.column;j++)
        {
            data[i][j]=obj.data[i][j];
        }
    return *this;
}
Matrix Matrix::operator ! () const
{
    Matrix tmp(column,row);
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            tmp.data[j][i]=data[i][j];
    return tmp;
}
Matrix Matrix::operator [] (unsigned i) const
{
    Matrix tmp(1,column);
    for(int j=0;j<column;j++)
        tmp.data[1][j]=data[i][j];
    return tmp;
}
Matrix Matrix::operator ()(unsigned j)const
{
    Matrix tmp(row,1);
    for(int i=0;i<row;i++)
        tmp.data[i][1]=data[i][j];
    return tmp;

}
Matrix::operator int () const
{
    return data[1][1];
}