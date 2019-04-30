//
// Created by Yangwenlu on 2019/4/30.
//

#ifndef MATRIX_CPP_NEW_MATRIX_H
#define MATRIX_CPP_NEW_MATRIX_H

#include <cmath>

template <typename T>
class MatrixBase;


template <typename T>
class Matrix  :public MatrixBase<T>
{
public:
    typedef MatrixBase<T> Base;

    using Base::Rows;
    using Base::Cols;
    using Base::Size;
    using Base::Data;
    using Base::operator+=;
    using Base::operator-=;
    using Base::operator*=;


    Matrix();
    Matrix(const Matrix<T>& mat);
    Matrix(size_t NumRow,size_t NumCol);
    Matrix<T>& operator=(const Matrix<T>& mat);

    //重载操作符号
    const Matrix<T> operator+(const Matrix<T> &mat) const; //矩阵加矩阵
    const Matrix<T> operator+(const T &num) const; //矩阵加标量
    const Matrix<T> operator-(const Matrix<T> &mat) const;

    const Matrix<T> operator-(const T &num) const;

    const Matrix<T> operator-() const;

    const Matrix<T> operator*(const Matrix<T> &mat) const;

    const Matrix<T> operator*(const T &num) const;

    friend const Matrix<T> operator*(const T &num, const Matrix<T> &mat) {
        return mat * num;
    }


};

template <typename T>
Matrix<T>::Matrix()
    :Base()
{

}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &mat)
{

}

template <typename T>
Matrix<T>::Matrix(size_t NumRow, size_t NumCol)
:Base(NumRow,NumCol)
{

}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat)
{

}

template <typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T> &mat) const //矩阵加矩阵
{
    Matrix<T> RC(*this);
    RC += mat;
    return RC;
}

template <typename T>
const Matrix<T> Matrix<T>::operator+(const T &num) const
{
    Matrix<T> RC(*this);
    RC += num;
    return RC;
}

#endif //MATRIX_CPP_NEW_MATRIX_H
