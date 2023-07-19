#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include "../inputValidation/inputValidation.h"
#include <iostream>

using namespace std;

typedef struct Matrix {
    int rows;
    int columns;
    double** matrix;
    string name;
} Matrix;

void readDimensions(Matrix& matrix);
double** reserveMatrixMemory(int rows, int columns);
Matrix createMatrix(int rows, int columns); // if the matrix does not have rows and columns alrready
void createMatrix(Matrix& matrix); // if the matrix already has rows and columns
void readMatrix(Matrix& matrix);
void printMatrix(Matrix matrix);
void deleteMatrix(Matrix& matrix);

void copyMatrix(Matrix& matrixA, Matrix matrixB);
Matrix addMatrices(Matrix matrixA, Matrix matrixB);
Matrix multiplyMatrices(Matrix matrixA, Matrix matrixB);
Matrix multiplyMatrixByScalar(Matrix matrix, double scalar);
Matrix getTransposedMatrix(Matrix matrix);

#endif