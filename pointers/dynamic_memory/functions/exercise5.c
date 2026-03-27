#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter range of array: ");
    int n;
    scanf("%d", &n);

    if(n <= 0) {
        return 1;
    }

    printf("Range of array is: %d\n", n);

    int *arr = (int *)malloc(n * sizeof *arr);

    if(arr == NULL) {
        return 1;
    }

    int num;
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter number of element #%d: ", i + 1);
        scanf("%d", &num);
        *(arr + i) = num;
    }

    // for (i = (n - 1); i >= 0; i--) {
    //     printf("Element #%d: %d\n", (i + 1), *(arr + i));
    // }

    int *p = arr + n - 1;
    while(p >= arr) {
        printf("%d", *p);
        p--;
    }

    free(arr);

    return 0;
}