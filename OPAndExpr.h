//
// Created by Yangwenlu on 2019/4/30.
//

#ifndef MATRIX_CPP_NEW_OPANDEXPR_H
#define MATRIX_CPP_NEW_OPANDEXPR_H

#include <cmath>

template <typename T>
class MatrixBase;

template <typename T>
class Block;


template <typename T>
class AssignmentExpr
{
public:
    explicit AssignmentExpr(const T& Value) {};
protected:

};

template <>
template <typename T>
class AssignmentExpr<Block<T>>
{
public:
    explicit AssignmentExpr(const Block<T>& BlockMat)
    :m_data(BlockMat.Data()),m_StartRow(BlockMat.StartRow()),
     m_StartCol(BlockMat.StartCol()),m_NumRow(BlockMat.BlockRow()),
     m_NumCol(BlockMat.BlockCol())
    {

    }

    T** Data() {return m_data;};
    size_t StartRow() {return m_StartRow;};
    size_t StartCol() {return m_StartCol;};
    size_t NumRow() {return m_NumRow;};
    size_t NumCol() {return m_NumCol;};

protected:
    T** m_data;
    size_t m_StartRow;
    size_t m_StartCol;
    size_t m_NumRow;
    size_t m_NumCol;

};






template <>
template <typename T>
class AssignmentExpr<MatrixBase<T>>
{
public:
    explicit AssignmentExpr(const MatrixBase<T>& Mat)
    :m_data(Mat.Data()),m_StartRow(0),m_StartCol(0),
     m_NumRow(Mat.Row()),m_NumCol(Mat.Col())
    {

    }
    T** Data() {return m_data;};
    size_t StartRow() {return m_StartRow;};
    size_t StartCol() {return m_StartCol;};
    size_t NumRow() {return m_NumRow;};
    size_t NumCol() {return m_NumCol;};

protected:
    T** m_data;
    size_t m_StartRow;
    size_t m_StartCol;
    size_t m_NumRow;
    size_t m_NumCol;

};

#endif //MATRIX_CPP_NEW_OPANDEXPR_H
