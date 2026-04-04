/*
Напиши функцію createMatrix яка приймає int **matrix, int rows,
int cols і виділяє пам'ять для одновимірного масиву розміром rows * cols.
В main передай адресу вказівника, заповни матрицю числами від 1 до rows * cols і виведи.
*/
#include <stdio.h>
#include <stdlib.h>

void createMatrix(int **matrix, int rows, int cols) {
    int size = (rows * cols);
    int *arr = (int *)malloc(size * sizeof *arr);
    if(*arr != NULL) {
        for (i = 0; i < size; i++) {
            *(*arr + i) = i + 1;
        }
    }
}

int main() {
    return 0;
}