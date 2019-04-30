#include "Matrix.h"
#include "MatrixBase.h"


int main()
{
    Matrix<double> A(2,2);
    Matrix<double> B(2,2);

    Matrix<double> C(2,2);

    C = A + B;

    return 0;

}