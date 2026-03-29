#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const int size = 5;
    int *arr = (int *)malloc(size * sizeof *arr);

    if(arr = NULL) {
        return 1;
    }
    
    memset(arr, 0, size * sizeof *arr);

    for (int i = 0; i < size; i++)
    {
        printf("Element #%d: %d\n", i + 1, *(arr + i));
    }

    free(arr);

    return 0;
}