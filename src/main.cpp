#include "getch/getch.h"
#include "inputValidation/inputValidation.h"
#include "matrix/matrix.h"

#include <iostream>

using namespace std;

int main()
{
    int option;
    Matrix matrixA;
    matrixA.name = "Matrix A";
    Matrix matrixB;
    matrixB.name = "Matrix B";
    Matrix resultMatrix;

    while (true) {
        cout << "WELCOME TO MatrixCalculator\n";
        cout << endl;
        cout << "[1].\tAdd matrices\n";
        cout << "[2].\tMultiply matrixes\n";
        cout << "[3].\tMultiply matrix by scalar\n";
        cout << "[4].\tGet a matrix transposed\n";
        cout << endl;
        cout << "[0].\tLeave\n";

        readInt(option);

        if (option == 0) {
            cout << "leaving...\n";
            break;
        }

        switch (option) {
        case 1:
            readDimensions(matrixA);
            createMatrix(matrixA);

            readDimensions(matrixB);
            createMatrix(matrixB);

            if ((matrixA.rows != matrixB.rows) || (matrixA.columns != matrixB.columns)) {

                cout << endl
                     << "Matrices must have the same dimensions" << endl;
                getch();
                break;
            }
            getch();

            readMatrix(matrixA);
            printMatrix(matrixA);
            getch();

            readMatrix(matrixB);
            printMatrix(matrixB);
            getch();

            resultMatrix = addMatrices(matrixA, matrixB);
            printMatrix(matrixA);
            cout << "+" << endl;
            printMatrix(matrixB);
            cout << "The result of the sum is: " << endl;
            printMatrix(resultMatrix);

            deleteMatrix(matrixA);
            deleteMatrix(matrixB);
            deleteMatrix(resultMatrix);

            getch();
            break;
        case 2:

            readDimensions(matrixA);
            readDimensions(matrixB);

            if (matrixA.columns != matrixB.rows) {
                cout << "Cannot Multiply. Matrix A rows and Matrix B columns must be the same" << endl;
                break;
            }
            getch();

            createMatrix(matrixA);
            createMatrix(matrixB);

            readMatrix(matrixA);
            readMatrix(matrixB);

            resultMatrix = multiplyMatrices(matrixA, matrixB);

            printMatrix(matrixA);
            cout << "*" << endl;
            printMatrix(matrixB);
            cout << "=" << endl;
            printMatrix(resultMatrix);

            createMatrix(matrixA);
            createMatrix(matrixB);
            createMatrix(resultMatrix);
            getch();
            break;
        // test
        default:
            cout << "Invalid option" << endl;
            getch();
            break;
        }
    }

    return 0;
}
