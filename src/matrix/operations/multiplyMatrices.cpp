#include "../matrix.h"

Matrix multiplyMatrices(Matrix matrixA, Matrix matrixB)
{
    Matrix resultMatrix;

    if (matrixA.columns != matrixB.rows) {
        cout << "Cannot multiply. Matrix A rows and Matrix B columns must be the same" << endl;
        exit(EXIT_FAILURE);
    }
    // at this point:
    //               matrixA.columns == matrixB.rows
    resultMatrix = createMatrix(matrixA.rows, matrixB.columns);
    // relsultMatrix.rows = matrixA.rows
    // resultMatrix.columns = matrixB.columns
    resultMatrix.name = "Result Matrix";
    printMatrix(resultMatrix);

    for (int i = 0; i < matrixA.rows; i++) {
        for (int j = 0; j < matrixB.columns; j++) {
            for (int k = 0; k < matrixA.columns; k++) {
                resultMatrix.matrix[i][j] += matrixA.matrix[i][k] * matrixB.matrix[k][j];
            }
        }
    }
    return resultMatrix;
}