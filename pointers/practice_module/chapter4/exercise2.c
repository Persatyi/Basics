/*
Напиши функцію яка динамічно виділяє одновимірний масив через malloc, заповнює його числами від 1 до n, і повертає вказівник.
*/
#include <stdlib.h>
#include <stdio.h>
int *createArr(int range) {
    int *arr = (int *)malloc(range * sizeof *arr);

    if(arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < range; i++) {
        *(arr + i) = i + 1;
    }

    return arr;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(arr + i));
    }
}
// Наступне завдання: напиши main де викликаєш цю функцію, виводиш масив, і правильно звільняєш пам'ять.
int main() {
    int range = 20;
    int *arr = createArr(range);
    printArray(arr, range);
    free(arr);
    arr = NULL;
    
    return 0;
}