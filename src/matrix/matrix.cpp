#include "matrix.h"

void readDimensions(Matrix& matrix) // when we
{
    cout << "### " << matrix.name << endl;

    cout << "Enter the number of rows for " << matrix.name << ": ";
    while (true) {
        readInt(matrix.rows);
        if (matrix.rows > 0) {
            break;
        }
        cout << "Rows must be greater than 0, try again: ";
    }

    cout << "Enter the number of columns for " << matrix.name << ": ";
    while (true) {
        readInt(matrix.columns);
        if (matrix.columns > 0) {
            break;
        }
        cout << "Columns must be greater than 0, try again: ";
    }
}

double** reserveMatrixMemory(int rows, int columns)
{
    if (rows <= 0 || columns <= 0) {
        cout << "Dimensions must be grater than 0" << endl;
        exit(EXIT_FAILURE);
    }

    double** matrix;

    matrix = new double*[rows];

    for (int row = 0; row < rows; row++) {
        matrix[row] = new double[columns];
    }
    return matrix;
}

Matrix createMatrix(int rows, int columns)
{
    Matrix matrix;
    matrix.rows = rows;
    matrix.columns = columns;
    matrix.matrix = reserveMatrixMemory(rows, columns);

    return matrix;
}
void createMatrix(Matrix& matrix)
{
    matrix.matrix = reserveMatrixMemory(matrix.rows, matrix.columns);
}

void readMatrix(Matrix& matrix)
{
    int count = 0;
    int total = matrix.columns * matrix.rows;

    for (int row = 0; row < matrix.rows; row++) {
        for (int column = 0; column < matrix.columns; column++) {
            cout << "Reading " << matrix.name << endl;
            printMatrix(matrix);
            printf("(%d/%d) Enter for [%d][%d]: ", ++count, total, row + 1, column + 1);
            readDouble(matrix.matrix[row][column]);
            system("clear");
        }
    }
}

//
void printHyphens(int columns)
{
    cout << "--";
    for (int i = 0; i < columns; i++) {
        cout << "-----------"; // 10 + 1
    }
    cout << "-";
    cout << endl;
}

void printMatrix(Matrix matrix)
{
    printHyphens(matrix.columns);
    cout << matrix.name << endl;

    for (int row = 0; row < matrix.rows; row++) {
        cout << "| ";
        for (int column = 0; column < matrix.columns; column++) {

            printf("%10.2lf ", matrix.matrix[row][column]);
        }
        cout << "|";
        cout << endl;
    }
    printHyphens(matrix.columns);
}

void deleteMatrix(Matrix& matrix)
{
    for (int row = 0; row < matrix.rows; row++) {
        delete[] matrix.matrix[row];
        matrix.matrix[row] = nullptr;
    }
    delete[] matrix.matrix;
    matrix.matrix = nullptr;

    matrix.rows = 0;
    matrix.columns = 0;
}

void copyMatrix(Matrix& matrixA, Matrix matrixB)
{
    deleteMatrix(matrixA);
    matrixA = createMatrix(matrixB.rows, matrixB.columns);

    for (int row = 0; row < matrixB.rows; row++) {
        for (int column = 0; column < matrixB.columns; column++) {
            matrixA.matrix[row][column] = matrixB.matrix[row][column];
        }
    }
}