/*
Напиши функцію яка динамічно виділяє двовимірний масив через int **matrix і заповнює його
*/
#include <stdlib.h>
int *createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof *matrix);
    matrix[0] = (int *)malloc(rows * cols * sizeof(int));
}