/*
Напиши функцію void swap(int *a, int *b) що міняє значення двох змінних місцями. Потім викличи її в main для x=5, y=10 і виведи результат.
*/
#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 5;
    int y = 10;
    swap(&x, &y);
    printf("x: %d\ny: %d\n", x, y);
    return 0;
}