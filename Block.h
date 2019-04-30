//
// Created by Yangwenlu on 2019/4/30.
//

#ifndef MATRIX_CPP_NEW_BLOCK_H
#define MATRIX_CPP_NEW_BLOCK_H

#include <cmath>
#include "DenseMatData.h"

template <typename T>
class DenseMatData;

template <typename T>
class Block:public DenseMatData<T>
{
public:
    typedef DenseMatData<T> Base;

    using Base::Data;


    Block(const DenseMatData<T>& SrcMat,
            size_t StartRow,
            size_t StartCol,
            size_t BlockRow,
            size_t BlockCol);


    size_t StartRow() {return m_StartRow;};
    size_t StartCol() {return m_StartCol;};
    size_t BlockRow() {return m_BlockRow;};
    size_t BlockCol() {return m_BlockCol;};


private:

    T** SrcData;

    size_t m_StartRow;
    size_t m_StartCol;
    size_t m_BlockRow;
    size_t m_BlockCol;

};


template <typename T>
Block<T>::Block(const DenseMatData<T>& SrcMat,
                size_t StartRow,
                size_t StartCol,
                size_t BlockRow,
                size_t BlockCol)
    :Base(BlockRow,BlockCol),SrcData(SrcMat.Data()),
    m_StartRow(StartRow),m_StartCol(StartCol),
    m_BlockRow(BlockRow),m_BlockCol(BlockCol)
{

}


#endif //MATRIX_CPP_NEW_BLOCK_H
