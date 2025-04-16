#include <stdio.h>
#include <stdlib.h>

void is_beneficial(int row, int col, int nzEle)
{
    if ((row * col) > ((nzEle + 1) * 3))
        printf("Triplet form is benficial");
    else
    {
        printf("Triplet form is not benficial");
        exit(0);
    }
}

int **inputSparseMatrix(int row, int col, int nzEle)
{
    int **mat;
    int i, r, c;

    mat = (int **)calloc(row, sizeof(int *));
    for (i = 0; i < col; i++)
    {
        mat[i] = (int *)calloc(col, sizeof(int));
    }

    printf("Enter the number of non zero elements in the matix\n");
    for (i = 0; i < nzEle; i++)
    {
        printf("Enter row number");
        scanf("%d", &r);
        printf("Enter coloumn number");
        scanf("%d", &c);
        printf("Enter the value to store");
        scanf("%d", &mat[r][c]);
    }
    return mat;
}

void displaySparseMatrix(int **mat, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int **tripletForm(int **mat, int row, int col, int nzEle)
{
    int i, j, k = 1;
    int **arrT;

    arrT = (int **)malloc((nzEle + 1) * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        arrT[i] = (int *)malloc(3 * sizeof(int));
    }

    arrT[0][0] = row;
    arrT[0][1] = col;
    arrT[0][2] = nzEle;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (mat[i][j] != 0)
            {
                arrT[k][0] = i;
                arrT[k][1] = j;
                arrT[k][2] = mat[i][j];
                k++;
            }
        }
    }

    printf("\n The triplet form is:\n");
    for (i = 0; i < nzEle + 1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", arrT[i][j]);
        }
        printf("\n");
    }

    return arrT;
}

int **transposeMatrix(int **arrT, int nzEle)
{
    int i;
    int **arrTrans = (int **)malloc((nzEle + 1) * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        arrTrans[i] = (int *)malloc(3 * sizeof(int));
    }

    for (i = 0; i < nzEle + 1; i++)
    {
        arrTrans[i][0] = arrT[i][1];
        arrTrans[i][1] = arrT[i][0];
        arrTrans[i][2] = arrT[i][2];
    }

    return arrTrans;
}

int **tripletToMat(int **arrTrans, int row, int col, int nzEle)
{
    int i, j, k = 0, l = 0;

    int **res = (int **)calloc(row, sizeof(int *));
    for (i = 0; i < col; i++)
    {
        res[i] = (int *)calloc(col, sizeof(int));
    }

    for (i = 1; i < nzEle + 1; i++)
    {
        // k=arrTrans[i][0];
        // l=arrTrans[i][1];
        res[arrTrans[i][0]][arrTrans[i][1]] = arrTrans[i][2];
    }
    return res;
}

int main()
{
    int r, c, no;
    int **matrix, **triplet, **transpose, **transposedMatrix;
    printf("Number of rows:");
    scanf("%d", &r);
    printf("Number of coloumns:");
    scanf("%d", &c);
    printf("Number of non zero elemts:");
    scanf("%d", &no);

    is_beneficial(r, c, no);

    matrix = inputSparseMatrix(r, c, no);
    displaySparseMatrix(matrix, r, c);
    triplet = tripletForm(matrix, r, c, no);
    transpose = transposeMatrix(triplet, no);
    displaySparseMatrix(transpose, r, c);

    return 0;
}