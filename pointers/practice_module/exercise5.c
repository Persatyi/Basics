/*
Напиши функцію void modifyValue(int **ptr) що приймає вказівник на вказівник
і змінює адресу на нову виділену пам'ять з malloc, записує туди 42. Викличи в main.
*/
#include <stdio.h>
#include <stdlib.h>

void modifyValue(int **ptr) {
    *ptr = (int*)malloc(sizeof **ptr);
    **ptr = 42;
}

int main() {
    int *ptr;
    modifyValue(&ptr);
    printf("%d", *ptr);
    free(ptr);
    ptr = NULL;

    return 0;
}