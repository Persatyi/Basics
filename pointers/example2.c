#include <stdio.h>

int main() {
    int num = 0;
    int *pi = &num;

    printf("Address of num: %d Value: %d\n", &num, num);
    printf("Address of pi: %d Value: %d\n", &pi, pi);

    *pi = 100;
    printf("%d\n", *pi); // Displays 100

    // f the intent was to assign the null value to pi, we use the NULL type as follows:
    pi = NULL;
    // A pointer can be used as the sole operand of a logical expression. For example, we can
    //test to see whether the pointer is set to NULL using the following sequence:

    if(pi) {
        // Not NULL
    } else {
        // Is NULL
    }

    return 0;
}