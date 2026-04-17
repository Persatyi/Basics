// You may encounter a function declared as follows. It is passed a single pointer and the
// number of rows and columns:
#include <stdio.h>

void display2DArrayUnknownSize(int *arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // The printf statement calculates the address of each element by adding to arr the num‐
            // ber of elements in the previous row(s), (i*cols), and then adding j to specify the
            // column. 
            // printf("%d ", *(arr + (i * cols) + j));
            // Within the function, we cannot use array subscripts as shown below:
            // printf("%d", arr[i][j]);
            // This is not possible because the pointer is not declared as a two-dimensional array.

            /*
            We can use a single subscript since it will be interpreted simply as an offset within the array, 
            whereas two subscripts cannot be used because the compiler doesn’t know the size of the dimensions:
            */
            printf("%d ", (arr + i)[j]);
            /*
            The first element’s address is passed using &matrix[0][0] instead of matrix. While
            using matrix will execute correctly, a warning will be generated, indicating incompatible
            pointer types. The expression &matrix[0][0] is a pointer to an integer, whereas matrix
            is a pointer to an array of integers.
            */
        }
        printf("\n");
    }
}

int main() {
    int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    display2DArrayUnknownSize(&matrix[0][0], 2, 5);
    return 0;
}