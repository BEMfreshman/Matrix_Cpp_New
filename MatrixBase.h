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

    //赋值操作符号
    MatrixBase(const MatrixBase<T>& mat);
    MatrixBase<T>& operator=(const Base& mat);



protected:
    MatrixBase();
    MatrixBase(size_t NumRow,size_t NumCol);

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
    //ToDo:深拷贝

    operator=(mat);
}

template <typename T>
MatrixBase<T>& MatrixBase<T>::operator=(const Base& mat)
{
    assigment_fun(*this,mat);
}


#endif //MATRIX_CPP_NEW_MATRIXBASE_H
