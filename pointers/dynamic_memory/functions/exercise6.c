#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter range of array: ");
    scanf("%d", &n);

    if(n <= 0) {
        return 1;
    }

    printf("Range of array is: %d\n", n);

    int *arr = (int *)malloc(n * sizeof *arr);

    if(arr == NULL) {
        return 1;
    }

    int *arr_p = arr;
    int even_count = 0;
    int i;

    for (i = 0; i < n; i++, arr_p++) {
        printf("Enter number of element #%d: ", i + 1);
        scanf("%d", arr_p);
        if(*(arr_p) % 2 == 0) {
            even_count++;
        }
    }

    arr_p = arr; // вертаю поінтер на початок масиву

    if(even_count != 0) {
        int *even_arr = (int *)malloc(even_count * sizeof *even_arr);
        int *even_p = even_arr;

        while(arr_p < arr + n) {
             if(*(arr_p) % 2 == 0) {
                *(even_p) = *(arr_p);
                even_p++;
            }
            arr_p++;
        }

        even_p = even_arr;

        while(even_p < even_arr + even_count) {
             printf("%d ", *even_p);
             even_p++;
        }

        free(even_arr);
        even_arr = NULL;
    } else {
        printf("There is no even numbers\n");
    }
    
    free(arr);
    arr = NULL;

    return 0;
}