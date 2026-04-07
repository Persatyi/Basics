#include <stdio.h>

double add(int num1, int num2) {
    return num1 + num2;
}

double substruct(int num1, int num2) {
    return num1 - num2;
}

double multiply(int num1, int num2) {
    return num1 * num2;
}

double divide(int num1, int num2) {
    if(num2 != 0) {
        return (double)num1 / num2;
    }

    return -1;
}

typedef double (*fptrOperation)(int, int);

fptrOperation evaluate(char opt) {
    switch(opt) {
        case '+':
            return add;
        case '-':
            return substruct;
        case '*':
            return multiply;
        case '/':
            return divide;
    }
}

double operate(char opt, int num1, int num2) {
    fptrOperation operation = evaluate(opt);
    return operation(num1, num2);
}

int main() {
    printf("%g\n", operate('+', 8, 7));
    printf("%g\n", operate('-', 8, 7));
    printf("%g\n", operate('*', 8, 7));
    printf("%f\n", operate('/', 8, 7));

    return 0;
}