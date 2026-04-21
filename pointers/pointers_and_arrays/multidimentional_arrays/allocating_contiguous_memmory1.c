/*
The first technique is illustrated in the following sequence. The first malloc allocates
an array of pointers to integers. Each element will be used to hold a pointer to a row.
*/
#include <stdlib.h>

int rows = 2;
int columns = 5;
int **matrix = (int **)malloc(rows * sizeof(int *));
matrix[0] = (int *)malloc(rows * columns * sizeof(int));
for (int i = 1; i < rows; i++) {
    matrix[i] = matrix[0] + i * columns;
}

// In the second technique shown below, all of the memory for the array is allocated at one
// time:

int *matrix2 = (int *)malloc(rows * columns sizeof(int));   

/*
When the array is referenced later in code, array subscripts cannot be used. Instead,
indexes into the array need to be calculated manually, as illustrated in the following code
sequence. Each array element is initialized to the product of its indexes:
*/

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        *(matrix2 + (i * columns) + j) = i * j;
    }
}

// Array subscripts cannot be used because we have lost the shape information needed by
// the compiler to permit subscripts.