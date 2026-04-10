/*
Напиши функцію int** createMatrix(int rows, int cols)
що виділяє 2D масив динамічно (масив вказівників на масиви). 
Не треба заповнювати, просто виділити і повернути.
*/

int** createMatrix(int rows, int cols) {
    int **matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    return matrix;
}