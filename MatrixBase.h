//
// Created by Yangwenlu on 2019/4/29.
//

#ifndef MATRIX_CPP_NEW_MATRIXBASE_H
#define MATRIX_CPP_NEW_MATRIXBASE_H

#include "DenseMatData.h"

template <typename T>
class MatrixBase:public DenseMatData<T>
{
public:
    typedef DenseMatData<T> Base;

    using Base::Rows;
    using Base::Cols;
    using Base::Size;
    using Base::Data;


    //赋值操作符号

    MatrixBase<T>& operator=(const Base& mat);




    /*操作符*/
    MatrixBase<T> &operator-();

    MatrixBase<T> &operator+=(const MatrixBase<T> &mat);

    MatrixBase<T> &operator+=(const T &value);

    MatrixBase<T> &operator-=(const MatrixBase<T> &mat);

    MatrixBase<T> &operator-=(const T &value);

    MatrixBase<T> &operator*=(const MatrixBase<T> &mat);      //mat必须是方阵
    MatrixBase<T> &operator*=(const T &num);

    MatrixBase<T> &operator/=(const T &num);

    T &operator()(size_t index_row, size_t index_col);//将函数操作符重载，实现寻址操作符功能
    const T operator()(size_t index_row, size_t index_col) const;//供常对象使用

protected:
    MatrixBase();
    MatrixBase(const MatrixBase<T>& mat);
    MatrixBase(size_t NumRow,size_t NumCol);


protected:


};

template <typename T>
MatrixBase<T>::MatrixBase()
    :Base(0,0)
{

}

template <typename T>
MatrixBase<T>::MatrixBase(size_t NumRow,size_t NumCol)
    :Base(NumRow,NumCol)
{

}

template <typename T>
MatrixBase<T>::MatrixBase(const MatrixBase<T> &mat)

{

}

template <typename T>
MatrixBase<T>& MatrixBase<T>::operator=(const Base& mat)
{
 //   assigment_fun(*this,mat);
}

template <typename T>
MatrixBase<T> &MatrixBase<T>::operator-()
{
    T** data = Data();
    for(size_t i = 0 ; i < this->Rows();i++)
    {
        for(size_t j = 0 ; j < this->Cols();j++)
        {
            data[i][j] = - data[i][j];
        }
    }

    return *this;
}

template <typename T>
MatrixBase<T>& MatrixBase<T>::operator+=(const MatrixBase<T> &mat)
{
    if(this->Rows() != mat.Rows() || this->Cols() != mat.Cols())
    {
        throw runtime_error("The dimension of two mat is not equal");
    }

    T** data = Data();
    for(size_t i = 0 ;i <this->Rows();i++)
    {
        for(size_t j = 0 ; j < this->Cols();j++)
        {
            data[i][j] +=  mat.Data()[i][j];
        }
    }

    return *this;
}

template <typename T>
MatrixBase<T>& MatrixBase<T>::operator+=(const T &value)
{
    T** data = Data();
    for(size_t i = 0 ;i <this->Rows();i++)
    {
        for(size_t j = 0 ; j < this->Cols();j++)
        {
            data[i][j] +=  value;
        }
    }

    return *this;
}

template <typename T>
MatrixBase<T>& MatrixBase<T>::operator-=(const MatrixBase<T> &mat)
{
    return operator+=(-mat);
}

template <typename T>
MatrixBase<T>& MatrixBase<T>::operator-=(const T &value)
{
    return operator+=(-value);
}


#endif //MATRIX_CPP_NEW_MATRIXBASE_H
