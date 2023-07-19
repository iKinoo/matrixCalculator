#include "../matrix.h"

Matrix getTransposedMatrix(Matrix matrix)
{
    Matrix transposedMatrix = createMatrix(matrix.columns, matrix.rows);

    for (int row = 0; row < transposedMatrix.rows; row++) {
        for (int column = 0; column < transposedMatrix.columns; column++) {
            transposedMatrix.matrix[row][column] = matrix.matrix[column][row];
        }
    }
    transposedMatrix.name = "Transposed Matrix";
    return transposedMatrix;
}