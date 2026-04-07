/*
Напиши функцію applyToArray яка приймає масив int, його розмір і вказівник на функцію.
Функція має застосовувати передану функцію до кожного елементу масиву і виводити результат.
Наприклад передаєш функцію square — виводить квадрат кожного елементу. 
Передаєш double — виводить подвоєне значення.
*/
#include <stdio.h>

int square(int num) {
    return num * num;
}

int doubleValue(int value) {
    return value + value;
}

typedef int (*fptr)(int);

void applyToArray(fptr func, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = func(*(arr+i));
    }
}

void printArray(int *arr, int range) {
    for (int i = 0; i < range; i++) {
        printf("%d ", *(arr + i));
    }
}

int main() {
    int size = 5;
    int arr[] = {5, 6, 77, 156, 12};
    applyToArray(square, arr, size);
    printArray(arr, size);
    printf("\n");
    applyToArray(doubleValue, arr, size);
    printArray(arr, size);

    return 0;
}