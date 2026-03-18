#include <stdio.h>

int main() {
    int vector[] = {28, 41, 7};
    int *pi = vector + 2; // pi: 108

    printf("%d\n", *pi); // Displays 7
    pi--;                // pi: 104
    printf("%d\n", *pi); // Displays 41
    pi--;                // pi: 100
    printf("%d\n", *pi); // Displays 28

    return 0;
}