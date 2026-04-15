/*
Parts of multidimensional arrays can be treated as subarrays. For example, each row of
a two-dimensional array can be treated as a one-dimensional array. This behavior affects
how we use pointers when dealing with multidimensional arrays.

*/
#include <stdio.h>

int main() {
    int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    // The addresses and their corresponding values are then displayed:
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("matrix[%d][%d] Adress: %p Value: %d\n", i, j, &matrix[i][j], matrix[i][j]);
        }
    }

    // We can declare a pointer for use with this array as follows:
    // If we had left the parentheses off, we would have declared
    // a five-element array of pointers to integers. 
    int (*pmatrix)[5] = matrix;

    /*
    The address returned by matrix+1 is not offset by 4 from the beginning of the array.
    Instead, it is offset by the first row’s size, 20 bytes. Using matrix by itself returns the
    address of the array’s first element. Since a two-dimensional array is an array of arrays,
    we get the address of a five-element integer array. Its size is 20
*/
    printf("%p\n", matrix);
    printf("%p\n", matrix + 1);

//  We can verify this with the following statement, which will display 20:
    printf("%d\n", sizeof(matrix[0]));

/*
    To access the array’s second element, we need to add 1 to the first row of the array as
    follows: *(matrix[0] + 1). The expression, matrix[0], returns the address of the first
    element of the first row of the array. This address is the address of an array of integers.
    Thus, when we add one to it, the size of a single integer is added to it, giving us the
    second element. The output will be 104 and 2.
*/
    printf("%p %d\n", matrix[0] + 1, *(matrix[0] + 1));
    printf("%d \n", matrix[1][2]);
    printf("%p %p\n", &matrix[1][2], (char*)matrix + 28);
    return 0;
}
