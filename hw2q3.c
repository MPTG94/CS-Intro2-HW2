#include<stdio.h>
#include <stdbool.h>

#define MATRIX_DIM 25

void PrintEnterMatrixDimension();

void GetMatrixInput(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension);

void CheckMatrixNilpotency(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index);

void PrintMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension);

void MultiplyMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension);

bool IsZeroMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension);

void LastZeroCheck(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index);

void PrintEnterMatrix();

void PrintEnterNilpotencyIndex();

void PrintItIsKNilpotenetMatrix(int k);

void PrintItIsNotKNilpotentMatrix(int k);

void PrintScannedMatrixIs();

int main() {
    int matrix[MATRIX_DIM][MATRIX_DIM] = {{0}};
    PrintEnterMatrixDimension();
    int dimension = 0, index = 0;
    scanf("%d", &dimension);
    PrintEnterMatrix();
    GetMatrixInput(matrix, dimension);
    PrintScannedMatrixIs();
    PrintMatrix(matrix, dimension);
    PrintEnterNilpotencyIndex();
    scanf("%d", &index);
    CheckMatrixNilpotency(matrix, dimension, index);
    return 0;
}

/**
 * Receives a matrix, it's dimension and an assumed nilpotency index and check if the matrix is k-nilpotent
 * @param matrix The matrix to check
 * @param dimension The matrix dimensions
 * @param index The assumed nilpotency index of the matrix
 */
void CheckMatrixNilpotency(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index) {
    if (index == 1 && IsZeroMatrix(matrix, dimension)) {
        PrintItIsKNilpotenetMatrix(index);
        return;
    }
    for (int i = 1; i < index; i++) {
        if (IsZeroMatrix(matrix, dimension)) {
            PrintItIsNotKNilpotentMatrix(index);
            return;
        }
        MultiplyMatrix(matrix, dimension);
    }
    LastZeroCheck(matrix, dimension, index);
}

/**
 * Performs a nilpotency check after all k iterations were performed
 * @param matrix The matrix to check
 * @param dimension The matrix dimensions
 * @param index The assumed nilpotency index of the matrix
 */
void LastZeroCheck(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index) {
    if (IsZeroMatrix(matrix, dimension)) {
        PrintItIsKNilpotenetMatrix(index);
    } else {
        PrintItIsNotKNilpotentMatrix(index);
    }
}

/**
 * Multiplies a matrix by itself
 * @param matrix The matrix to multiply
 * @param dimension The dimensions of the matrix
 */
void MultiplyMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension) {
    int temp[MATRIX_DIM][MATRIX_DIM] = {{0}};
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            for (int k = 0; k < dimension; ++k) {
                temp[i][j] += matrix[i][k] * matrix[k][i];
            }
        }
    }

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            matrix[i][j] = temp[i][j];
        }
    }
}

/**
 * Checks if the matrix is a zero-matrix
 * @param matrix The matrix to check
 * @param dimension The dimensions of the matrix
 * @return True if the matrix is a zero-matrix, false otherwise
 */
bool IsZeroMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Receives the cells of a matrix as input
 * @param matrix The 2-dimensional array to save the matrix to
 * @param dimension The dimensions of the matrix
 */
void GetMatrixInput(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension) {
    int input;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            scanf("%d", &input);
            matrix[i][j] = input;
        }
    }
}

/**
 * Prints the matrix
 * @param matrix The matrix to print
 * @param dimension The matrix dimensions
 */
void PrintMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void PrintEnterMatrixDimension() {
    printf("Please enter matrix dimension: ");
    return;
}

void PrintEnterMatrix() {
    printf("Please enter your matrix:\n");
    return;
}

void PrintEnterNilpotencyIndex() {
    printf("Please enter Nilpotency index: ");
    return;
}

void PrintItIsKNilpotenetMatrix(int k) {
    printf("It is %d-nilpotent matrix!\n", k);
    return;
}

void PrintItIsNotKNilpotentMatrix(int k) {
    printf("It is not %d-nilpotent matrix.\n", k);
    return;
}

void PrintScannedMatrixIs() {
    printf("Scanned matrix is:\n");
    return;
}