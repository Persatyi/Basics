/*
In the following example, a pointer to an integer array is passed, which will be
assigned memory and initialized. The function will return the allocated memory back
through the first parameter. In the function, we first allocate memory and then initialize
it. The address of this allocated memory is intended to be assigned to a pointer to an
int. To modify this pointer in the calling function, we need to pass the pointer’s address.
Thus, the parameter is declared as a pointer to a pointer to an int. In the calling function,
we need to pass the address of the pointer:
*/

#include <stdio.h>
#include <stdlib.h>

void allocateArray(int **arr, int size, int value) {
    *arr = (int *)malloc(size * sizeof *arr);
    if(*arr != NULL) {
        for (int i = 0; i < size; i++) {
            *(*arr + 1) = value;
        }
    }
}

int main() {
    int *vector = NULL;
    allocateArray(&vector, 5, 45);
    free(vector);
    
    return 0;
}