#include "../matrixOperations.h"

Matrix multiplyMatrixByScalar(Matrix matrix, double scalar)
{
    Matrix resultMatrix = createMatrix(matrix.rows, matrix.columns);
    copyMatrix(resultMatrix, matrix);

    for (int row = 0; row < resultMatrix.rows; row++) {
        for (int column = 0; column < resultMatrix.columns; column++) {
            resultMatrix.matrix[row][column] *= scalar;
        }
    }
    resultMatrix.name = "Result Matrix";
    return resultMatrix;
}