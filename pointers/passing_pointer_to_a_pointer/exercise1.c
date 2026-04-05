/*
Напиши функцію createMatrix яка приймає int **matrix, int rows,
int cols і виділяє пам'ять для одновимірного масиву розміром rows * cols.
В main передай адресу вказівника, заповни матрицю числами від 1 до rows * cols і виведи.
*/
#include <stdio.h>
#include <stdlib.h>

void createMatrix(int **matrix, int rows, int cols) {
    int size = (rows * cols);
    *matrix = (int *)malloc(size * sizeof **matrix);
    if(*matrix != NULL) {
        for (int i = 0; i < size; i++) {
            *(*matrix + i) = i + 1;
        }
    }
}

void printMatrix(int *matrix, int rows, int cols) {
    int size = (rows * cols);
    if(matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                 printf("%4d", *(matrix + i * cols + j));
            }
            printf("\n");
        }
    }
}

int main() {
    int *vector = NULL;
    createMatrix(&vector, 5, 7);
    printMatrix(vector, 5, 7);
    free(vector);
    vector = NULL;

    return 0;
}

