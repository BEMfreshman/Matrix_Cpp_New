//
// Created by Yangwenlu on 2019/4/29.
//

#ifndef MATRIX_CPP_NEW_UTILITY_H
#define MATRIX_CPP_NEW_UTILITY_H


#include "OPAndExpr.h"


template <typename DstT,typename SrcT>
void assigment_fun(DstT& dst,const SrcT& src)
{
    AssignmentExpr<DstT> dstExpr(dst);
    AssignmentExpr<SrcT> srcExpr(src);
}




#endif //MATRIX_CPP_NEW_UTILITY_H
