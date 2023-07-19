# MatrixCalculator

MatrixCalculator is a simple console app which is able to calculate operations related with matrices such as multiplying, sum, transposed, determinant, etc.

This mini project is for learning puposes and the code will be not clean at all.

----

## Some documentation

For create a matrix there is two ways:

1. Return an entire matrix struct like, this method uses rows and columns data for creating the matrix:
```c++
double rows = 3;
double columns = 3;
Matrix matrix = createMatrix(rows, columns);
```
2. Overwrite the matrix struct with already rows and columns (`matrix.rows` and `matrix.columns`), this method only accepts a matrix structure as a parameter:
```c++
Matrix matrix;
matrix.rows = 3;
matrix.columns = 4;
createMatrix(matrix);
```
Both methos should give a created matrix for the member of the matrix structure `matrix.matrix`, which is a `double**` type;

>*Yes I know, my English sucks*