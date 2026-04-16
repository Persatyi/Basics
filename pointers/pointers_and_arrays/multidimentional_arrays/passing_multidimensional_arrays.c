// To pass the matrix array, use either:
// void display2DArray(int arr[][5], int rows) 
// or:
// void display2DArray(int (*arr)[5], int rows) 
/*
In both versions the number of columns is specified. This is needed because the compiler
needs to know the number of elements in each row. If this information is not passed,
then it is unable to evaluate expressions such as arr[0][3]
*/
#include <stdio.h>

void display2DArray(int arr[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/*
When passing an array with more than two dimensions, all but the size of the first
dimension need to be specified. The following demonstrates a function written to dis‐
play a three-dimensional array. The last two dimensions are specified in the declaration:

*/
void display3DArray(int(*arr)[2][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2; j++) {
            printf("{");
            for (int k = 0; k < 4; k++) {
                printf("%d", arr[i][j][k]);
            }
            printf("}");
        }
        printf("\n");
    }
}

int main() {
    int matrix[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}};

    display2DArray(matrix, 2);

    int arr3d[3][2][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}},
        {{9, 10, 11, 12}, {13, 14, 15, 16}},
        {{17, 18, 19, 20}, {21, 22, 23, 24}}};

    display3DArray(arr3d, 3);

    return 0;
}

