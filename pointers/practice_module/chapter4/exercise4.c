/*
Напиши функцію яка динамічно виділяє двовимірний масив через int **matrix і заповнює його
*/
#include <stdlib.h>
#include <stdio.h>

int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof *matrix);
    if(matrix == NULL) {
        return NULL;
    }
    matrix[0] = (int *)malloc(rows * cols * sizeof(int));
        
    if(matrix[0] == NULL) {
        return NULL;
    }

    for (int i = 1; i < rows; i++) {
        matrix[i] = matrix[0] + i * cols;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }

    return matrix;
}

void printMatrix(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **arr = createMatrix(4, 5);
    printMatrix(arr, 4, 5);
    free(arr[0]);
    arr[0] = NULL;
    free(arr);
    arr = NULL;

    return 0;
}