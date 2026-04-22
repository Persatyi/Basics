/*
Напиши функцію яка приймає двовимірний масив int arr[][5] і виводить його елементи.
*/
#include <stdio.h>

void print2DArray(int(*arr)[5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[3][5] = {{10, 20, 30, 23, 34}, {40, 50, 60, 56, 12}, {70, 80, 90, 22, 88}};
    print2DArray(arr, 3);
    
    return 0;
}