#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    if(n <= 0) {
        return 0;
    }

    int *arr = calloc(n, sizeof *arr);
    
    if(arr == NULL) {
        return 1;
    }

    int *arr_p = arr;

    for (int i = 0; i < n; i++, arr_p++) {
        if(i % 2 == 0) {
            *(arr_p) = 1;
        }
    }

    arr_p = arr;

    while(arr_p < (arr + n)) {
        printf("%d ", *arr_p);
        arr_p++;
    }

    free(arr);

    return 0;
}