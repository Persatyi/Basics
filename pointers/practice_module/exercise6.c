/*
Напиши функцію int (*getOperation(char op))(int, int) що повертає вказівник на функцію:
 '+' → add, '-' → sub, '*' → mul. Викличи в main для '+' з числами (7, 3).
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

Operation getOperation(char op) {
    switch(op){
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return mul;
        default:
            return NULL;
    }
} 

int main() {
    Operation op = getOperation('+');
    printf("%d\n", op(7, 3));
    return 0;
}