//
// Created by Yangwenlu on 2019/4/29.
//

#ifndef MATRIX_CPP_NEW_DENSEMATDATA_H
#define MATRIX_CPP_NEW_DENSEMATDATA_H

#include <cmath>
#include <stdexcept>

using namespace std;

template <typename T>
class DenseMatData
{
public:
    virtual ~DenseMatData() = 0;


    size_t Rows() const{return m_NumRow;};
    size_t Cols() const{return m_NumCol;};
    size_t Size() const{return m_Size;};

    T** Data() {return m_data;};

protected:
    DenseMatData();
    DenseMatData(size_t NumRow,size_t NumCol);
    DenseMatData(const DenseMatData& DMD);

    void Allocate(size_t NumRow,size_t NumCol);
    void DeAllocate();


protected:
    T** m_data;
    size_t m_NumRow;
    size_t m_NumCol;
    size_t m_Size;

};

template <typename T>
void DenseMatData<T>::Allocate(size_t NumRow, size_t NumCol)
{
    if(NumRow == 0 || NumCol == 0)
    {
        throw runtime_error("NumRow or NumCol is equal to zero");
    }

    m_data = new T* [NumRow];

    for(size_t i = 0 ; i < NumRow;i++)
    {
        m_data[i] = new T [NumCol];
    }
}

template <typename T>
void DenseMatData<T>::DeAllocate()
{
    for (size_t i = 0; i < m_NumRow; ++i) {
        delete[] m_data[i];
        m_data[i] = nullptr;
    }
    delete[] m_data;
    m_data = nullptr;
    m_NumRow = 0;
    m_NumCol = 0;
}


template <typename T>
DenseMatData<T>::DenseMatData()
    :m_data(nullptr),m_NumRow(0),m_NumCol(0),m_Size(0)
{

}

template <typename T>
DenseMatData<T>::DenseMatData(size_t NumRow, size_t NumCol)
    :m_NumRow(NumRow),m_NumCol(NumCol),m_Size(NumRow * NumCol)
{
    try
    {
        Allocate(NumRow,NumCol);
    }
    catch(runtime_error& e)
    {
        throw e;
    }
}
template <typename T>
DenseMatData<T>::DenseMatData(const DenseMatData& DMD)
{
    Allocate(DMD.Rows(),DMD.Cols());
    for(size_t i = 0 ; i < DMD.Rows();i++)
    {
        for(size_t j = 0 ; j < DMD.Cols();j++)
        {
            m_data[i][j] = DMD.m_data[i][j];
        }
    }
}

template <typename T>
DenseMatData<T>::~DenseMatData()
{
    DeAllocate();
}






#endif //MATRIX_CPP_NEW_DENSEMATDATA_H
