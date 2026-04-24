/*
Масив з 3 вказівників int *arr[3]
Кожен вказівник вказує на масив різного розміру: 2, 4, і 3 елементи
Заповни кожен елемент будь-якими числами
Виведи всі елементи
Звільни пам'ять
*/
#include <stdlib.h>
#include <stdio.h>

void fillArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

int *createArray(int size){
    int *tmp = (int *)malloc(size * sizeof *tmp);
    if(tmp == NULL) {
        return NULL;
    }

    fillArr(tmp, size);

    return tmp;
}

void printArray( int *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateArray(int **arr, int size, int *sizes) {
    for (int i = 0; i < size; i++) {
        arr[i] = createArray(sizes[i]);
        printArray(arr[i], sizes[i]);
    }
}

void freeMem(int **arr, int size){
    for (int i = 0; i < size; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
}

int main() {
    int size = 3;
    int *arr[size];
    int sizes[] = {2, 4, 3};

    generateArray(arr, size, sizes);
    freeMem(arr, size);

    return 0;
}