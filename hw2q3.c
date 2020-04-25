#include<stdio.h>
#include <stdbool.h>

#define MATRIX_DIM 25

void PrintEnterMatrixDimension();

void GetMatrixInput(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension);

void CheckMatrixNilpotency(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index);

void PrintMatrix(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension);

bool TemporaryZeroCheck(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index);

void CopyMatrix(int source[MATRIX_DIM][MATRIX_DIM], int destination[MATRIX_DIM][MATRIX_DIM], int dimension);

void MultiplyMatrix(int first[MATRIX_DIM][MATRIX_DIM], int second[MATRIX_DIM][MATRIX_DIM], int dimension);

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
    int result[MATRIX_DIM][MATRIX_DIM] = {{0}};
    CopyMatrix(matrix, result, dimension);
    for (int i = 1; i < index; i++) {
        if (TemporaryZeroCheck(result, dimension, index)) {
            return;
        }
        MultiplyMatrix(matrix, result, dimension);
    }
    LastZeroCheck(result, dimension, index);
}

/**
 * Performs a check if the matrix is zeroed ahead of time
 * @param matrix The matrix to check
 * @param dimension The matrix dimensions
 * @param index The assumed nilpotency index of the matrix
 * @return true if the matrix is a zero matrix, false otherwise.
 */
bool TemporaryZeroCheck(int matrix[MATRIX_DIM][MATRIX_DIM], int dimension, int index) {
    if (IsZeroMatrix(matrix, dimension)) {
        PrintItIsNotKNilpotentMatrix(index);
        return true;
    }
    return false;
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
 * Copies a square matrix to a new matrix variable of the same dimensions
 * @param source The matrix to copy
 * @param destination The destination to copy into
 * @param dimension The dimensions of the two matrices
 */
void CopyMatrix(int source[MATRIX_DIM][MATRIX_DIM], int destination[MATRIX_DIM][MATRIX_DIM], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            destination[i][j] = source[i][j];
        }
    }
}

/**
 * Multiplies 2 square matrices with the same dimensions
 * @param first The first matrix to multiply
 * @param second the second matrix to multiply
 * @param dimension The dimensions of the matrices
 */
void MultiplyMatrix(int first[MATRIX_DIM][MATRIX_DIM], int second[MATRIX_DIM][MATRIX_DIM], int dimension) {
    int temp[MATRIX_DIM][MATRIX_DIM] = {{0}};
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            for (int k = 0; k < dimension; ++k) {
                temp[i][j] += second[i][k] * first[k][j];
            }
        }
    }
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            second[i][j] = temp[i][j];
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