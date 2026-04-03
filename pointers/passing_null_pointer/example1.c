#include <stdio.h>
#include <stdlib.h>

// If the pointer is NULL, then no action is performed and the program will execute
// without terminating abnormally.
int* allocateArray(int *arr, int size, int value) {
    if(arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }
    return arr;
}

void printArray(int *arr, int size) {
    if(arr != NULL) {
        for (int i = 0; i < size; i++) {
            printf("Element #%d: %d\n", i + 1, *(arr + i));
        }
    } else {
        printf("THere is no data in array");
    }
}

int main() {
int *vector = (int *)malloc(5 * sizeof *vector);
allocateArray(vector, 5, 45);
printArray(vector, 5);

free(vector);
vector = NULL;

return 0;
}