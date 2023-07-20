#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

#include "../matrix.h"

void copyMatrix(Matrix& matrixA, Matrix matrixB);
Matrix addMatrices(Matrix matrixA, Matrix matrixB);
Matrix multiplyMatrices(Matrix matrixA, Matrix matrixB);
Matrix multiplyMatrixByScalar(Matrix matrix, double scalar);
Matrix getTransposedMatrix(Matrix matrix);
Matrix getIdentityMatrix(Matrix matrix);

#endif