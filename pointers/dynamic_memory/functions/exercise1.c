#include <stdlib.h>
#include <stdio.h>

int main() {
    const int NUMBER_OF_ITEMS = 5;
    int *arr = (int *)malloc(NUMBER_OF_ITEMS * sizeof *arr);

    if (arr == NULL) return 1;
    
        for (int i = 0; i < NUMBER_OF_ITEMS; i++)
        {
            // arr[i] = i;
            // printf("%d ", arr[i]);
            // printf("%d \n", &arr[i]);

            *(arr + i) = i;
            printf("%d ", *(arr + i));
        }
        free(arr);
    

    return 0;
}