cmake_minimum_required(VERSION 3.13)
project(Matrix_Cpp_New)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix_Cpp_New
        Utility.h
        MatrixBase.h
        DenseMatData.h
        main.cpp)