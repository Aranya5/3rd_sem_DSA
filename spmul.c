#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a sparse matrix element
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to create a sparse matrix
void createSparseMatrix(int **matrix, int rows, int cols, struct SparseMatrix sparse[], int *size) {
    int k = 0; // Index for sparse matrix

    // Traverse the matrix and store non-zero elements in sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    *size = k;
}

// Function to multiply two sparse matrices
void multiplySparseMatrices(struct SparseMatrix sparseA[], int sizeA, struct SparseMatrix sparseB[], int sizeB, struct SparseMatrix result[], int *sizeR, int rowsA, int colsA, int colsB) {
    int temp[MAX][MAX] = {0};

    // Multiplying the matrices using sparse matrix representation
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (sparseA[i].col == sparseB[j].row) {
                temp[sparseA[i].row][sparseB[j].col] += sparseA[i].value * sparseB[j].value;
            }
        }
    }

    // Convert result matrix to sparse format
    int k = 0;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            if (temp[i][j] != 0) {
                result[k].row = i;
                result[k].col = j;
                result[k].value = temp[i][j];
                k++;
            }
        }
    }

    *sizeR = k;
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrix sparse[], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Read dimensions of the first matrix
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &colsA);

    // Allocate memory for the first matrix
    int **matrixA = (int **)malloc(rowsA * sizeof(int *));
    for (int i = 0; i < rowsA; i++) {
        matrixA[i] = (int *)malloc(colsA * sizeof(int));
    }

    // Read elements of the first matrix
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Read dimensions of the second matrix
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication not possible. Columns of A must match rows of B.\n");
        // Free allocated memory
        for (int i = 0; i < rowsA; i++) {
            free(matrixA[i]);
        }
        free(matrixA);
        return -1;
    }

    // Allocate memory for the second matrix
    int **matrixB = (int **)malloc(rowsB * sizeof(int *));
    for (int i = 0; i < rowsB; i++) {
        matrixB[i] = (int *)malloc(colsB * sizeof(int));
    }

    // Read elements of the second matrix
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    struct SparseMatrix sparseA[MAX], sparseB[MAX], result[MAX];
    int sizeA, sizeB, sizeR;

    createSparseMatrix(matrixA, rowsA, colsA, sparseA, &sizeA);
    createSparseMatrix(matrixB, rowsB, colsB, sparseB, &sizeB);

    multiplySparseMatrices(sparseA, sizeA, sparseB, sizeB, result, &sizeR, rowsA, colsA, colsB);

    printf("Resultant sparse matrix after multiplication:\n");
    displaySparseMatrix(result, sizeR);

    // Free allocated memory
    for (int i = 0; i < rowsA; i++) {
        free(matrixA[i]);
    }
    free(matrixA);

    for (int i = 0; i < rowsB; i++) {
        free(matrixB[i]);
    }
    free(matrixB);

    return 0;
}