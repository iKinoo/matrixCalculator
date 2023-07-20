#include "../matrixOperations.h"

Matrix addMatrices(Matrix matrixA, Matrix matrixB)
{
    Matrix resultMatrix;

    if (matrixA.rows != matrixB.rows || matrixA.columns != matrixB.columns) {
        cout << "Cannot sum. Matrices must have the same dimensions" << endl;
        exit(EXIT_FAILURE);
    }
    resultMatrix = createMatrix(matrixA.rows, matrixA.columns);
    resultMatrix.rows = matrixA.rows;
    resultMatrix.columns = matrixA.columns;
    resultMatrix.name = "Result Matrix";

    for (int row = 0; row < resultMatrix.rows; row++) {
        for (int column = 0; column < resultMatrix.columns; column++) {
            resultMatrix.matrix[row][column] = matrixA.matrix[row][column] + matrixB.matrix[row][column];
        }
    }
    return resultMatrix;
}
