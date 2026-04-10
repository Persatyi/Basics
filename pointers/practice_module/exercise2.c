/*
Створи масив з 3 function pointers на функції int add(int, int), int sub(int, int), int mul(int, int).
 В циклі викликай всі три для чисел (6, 3) і виводь результати.
*/
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

typedef int (*Operation)(int, int);

int main() {
    Operation arr[] = {add, sub, mul};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i](6, 3));
    }
    return 0;
}