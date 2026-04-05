/*
Напиши три функції — add, subtract, multiply які приймають два int і повертають int. 
Потім в main створи вказівник на функцію і по черзі присвоюй кожну функцію та 
викликай з числами 10 і 5.
*/
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int substract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int num1 = 10;
    int num2 = 5;
    typedef int (*Operation)(int, int);
    Operation fptr = add;
    printf("Sum of 5 and 10: %d\n", fptr(num1, num2));

    fptr = substract;
    printf("Substraction of 5 and 10: %d\n", fptr(num1, num2));

    fptr = multiply;
    printf("Multiply of 5 and 10: %d\n", fptr(num1, num2));

    return 0;
}