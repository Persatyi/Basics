#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    if (<= n) {
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof *arr);

    if(arr != NULL) {
        for (int i = 0; i < n; i++) {
            arr[i] = i;
            printf("%d ", arr[i]);
        }
    }

    free(arr);

    return 0;
}