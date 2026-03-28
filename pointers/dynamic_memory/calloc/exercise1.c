#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n <= 0) {
        return 1;
    }

    int *arr = calloc(n, sizeof *arr);

    if(arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}