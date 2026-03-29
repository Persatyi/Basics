/*
Створи масив з 5 елементів int через malloc, заповни його значеннями від 1 до 5,
 виведи. Потім через realloc розшир до 10 елементів, заповни нові елементи від 6 до 10,
  виведи весь масив.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int range = 5;
    int *arr = (int *)malloc(range * sizeof *arr);

    if(arr == NULL) {
        return 1;
    }

    int *arr_p = arr;
    int i;
    for (i = 0; i < range; i++, arr_p++) {
        *(arr_p) = i + 1;
        printf("%d ", *arr_p);
    }

    const int newRange = 10;
    int *arr2 = (int *)realloc(arr, newRange * sizeof *arr2);

    if(arr2 == NULL) {
        free(arr);
        arr = NULL;
        return 1;
    }

    arr_p = arr2 + range;

    for (i = range; i < newRange; i++, arr_p++) {
        *(arr_p) = i + 1;
         printf("%d ", *arr_p);
    }

    free(arr2);
    arr2 = NULL;
    arr = NULL;

    return 0;
}