#include "../matrix.h"

// Matrix columns must be at least >= matrix rows
Matrix getIdentityMatrix(Matrix matrix)
{
    if (matrix.columns < matrix.rows) {
        cout << "Matrix columns must be at least >= matrix rows" << endl;
        exit(EXIT_FAILURE);
    }

    Matrix identityMatrix;
    copyMatrix(identityMatrix, matrix);

    // # lets reduce this matrix to zeros
    /* This cycle must represent a square,
    the square part is the part that is goint to be the identity
    so, that's why we use `identityMatrix.rows` twice. */
    for (int column = 0; column < identityMatrix.rows; column++) {

        double pivot = identityMatrix.matrix[column][column];
        int pivotRow = column; // this is because `column` represents `identityMatrix.rows`

        for (int row = 0; row < identityMatrix.rows; row++) {

            if (row == column) {
                continue;
            }
            double coeficient = identityMatrix.matrix[row][column];

            for (int currentColumn = 0; currentColumn < identityMatrix.columns; currentColumn++) {
                identityMatrix.matrix[row][currentColumn] = (pivot * identityMatrix.matrix[row][currentColumn]) + (identityMatrix.matrix[pivotRow][currentColumn] * coeficient * (-1));
            }
        }
    }

    for (int row = 0; row < identityMatrix.rows; row++) {

        double pivot = identityMatrix.matrix[row][row];

        for (int column = 0; column < identityMatrix.columns; column++) {

            identityMatrix.matrix[row][column] /= pivot;
        }
    }
    identityMatrix.name = "Identity Matrix";

    return identityMatrix;
}