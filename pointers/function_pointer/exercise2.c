/*
Зроби простий калькулятор — масив з чотирьох вказівників на функції add, subtract, 
multiply, divide. Користувач вводить два числа і цифру операції (0-3), 
програма викликає потрібну функцію і виводить результат.
*/
#include <stdio.h>

typedef double (*Operation)(int, int);

double add(int a, int b) {
    return a + b;
}

double substract(int a, int b) {
    return a - b;
}

double multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if(b != 0) {
        return a / b;
    } else {
        return -1;
    }
}

void func(Operation *arr, int num, int a, int b) {
     switch (num) {
        case 1:
            printf("The sum of %d and %d is %f\n", a, b, arr[0](a, b));
            break;
        case 2:
            printf("The substraction of %d and %d is %f\n", a, b, arr[1](a, b));
            break;
        case 3:
            printf("The multiply of %d and %d is %f\n", a, b, arr[2](a, b));
            break;
        case 4:
            printf("The divide of %d and %d is %f\n", a, b, arr[3](a, b));
            break;
        default:
            printf("Wrong choice, please choose 1-4 for operation or 0 for exit\n");
            break;
        }

}

int main() {
    Operation arr[4] = {add, substract, multiply, divide};
    int num = 0;
    int a, b;
    do{
        printf("Enter a number '1-4' to choose operation, or 0 to exit.\n");
        printf("1 - add, 2 - substract, 3 - multiply, 4 - divide\n");
        printf("Operation: ");
        scanf("%d", &num);

        if(num == 0) {
            printf("Exiting program ...\n");
        } else if(num > 0 && num <= 4) {
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        func(arr, num, a , b);
        } else {
            printf("Wrong operation!\n");
        }
    } while (num != 0);

    return 0;
}