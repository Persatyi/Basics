/*
Створи дві функції int multiply(int a, int b) та int subtract(int a, int b).
Використай typedef void (*fptrBase)() як placeholder щоб обміняти вказівники
на ці дві функції місцями (спочатку fptr1 вказує на multiply, fptr2 на subtract, 
після обміну - навпаки). Викликай обидві після обміну і виведи результати для (8, 3).
*/
#include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

int substruct(int a, int b) {
    return a - b;
}

typedef int (*fptr)(int, int);
typedef void (*fptrbase)();

int main() {
    fptrbase placeholder;
    fptr fptr1 = multiply;
    fptr fptr2 = substruct;
    placeholder = (fptrbase)fptr1;
    fptr1 = fptr2;
    fptr2 = (fptr)placeholder;
    printf("%d\n", fptr1(5, 6));
    printf("%d\n", fptr2(5, 6));
    return 0;
}