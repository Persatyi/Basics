/*
The following declares a two-dimensional array with two rows and three columns. 
The array is initialized using a block statement.
A two-dimensional array is treated as an array of arrays. That is, when we access the
array using only one subscript, we get a pointer to the corresponding row
The size is 12 because each row has three elements of four bytes each:
*/
#include <stdio.h>

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int i = 0; i < 2; i++) {
        printf("&matrix[%d]: %p sizeof(matrix[%d]): %d\n", i, &matrix[i], i, sizeof(matrix[i]));
    }
        return 0;
}