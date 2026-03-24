#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
    printf("Invalid number!\n");
    return 1;
    }

    int *arr = (int *)malloc(n * sizeof *arr);

    if(arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        *(arr + i) = i;
        printf("%d\n", *(arr + i));
    }

    free(arr);

    return 0;
}
