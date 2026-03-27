#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    if(n <= 0) {
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof *arr);
    if(arr == NULL) {
        return 1;
    }

    int *p = arr;
    int sum = 0;
    int max;

    for (int i = 0; i < n; i++) {
        printf("Enter element #%d: ", i + 1);
        scanf("%d", p);
        sum += *p;
        if(i == 0) {
            max = *p;
        }

        if(*p > max) {
            max = *p;
        }
        p++;
    }

    printf("Sum: %d\n", sum);
    printf("Max: %d\n", max);

    free(arr);

    return 0;
}