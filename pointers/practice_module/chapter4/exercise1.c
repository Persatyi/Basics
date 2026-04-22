/*
напиши функцію яка приймає одновимірний масив і виводить його елементи. Без підглядання.
*/
#include <stdio.h>

void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        // printf("%d\n", arr[i]);
        printf("%d\n", *(arr + i));
    }
}

int main() {
    int arr[] = {10, 20, 30 ,40 ,50};
    int size = 5;
    printArr(arr, size);

    return 0;
}
