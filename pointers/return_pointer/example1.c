/*
In the following example, we define a function that is passed the size of an integer array
and a value to initialize each element. The function allocates memory for an integer
array, initializes the array to the value passed, and then returns the array’s address:
*/

#include <stdio.h>
#include <stdlib.h>

int* allocateArray(int size, int value) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }

    return arr;
}

// The following illustrates how this function can be used:
int main() {
    int *vector = allocateArray(5, 45);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", vector[i]);
    }

    free(vector);

    return 0;
}