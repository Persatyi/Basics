/*
The following illustrates one way of allocating a two-dimensional array where the al‐
located memory is not guaranteed to be contiguous. First, the “outer” array is allocated
and then each row is allocated using separate malloc statements:
*/
#include <stdlib.h>

int main() {
    int rows = 2;
    int columns = 5;
    
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);
    matrix = NULL;
    
    return 0;
}

