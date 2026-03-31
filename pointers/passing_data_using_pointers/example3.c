/*
Passing a Pointer to a Constant

void passingAddressOfConstants(const int* num1, int* num2) {
 *num1 = 100;
 *num2 = 200;
}
This will cause a problem if we pass the constant limit to the function twice:
 const int limit = 100;
 passingAddressOfConstants(&limit, &limit);
*/

#include <stdio.h>

void passingAddressOfConstants(const int* num1, int* num2) {
    *num2 = *num1;
}

int main() {
    const int limit = 100;
    int result = 5;
    passingAddressOfConstants(&limit, &result);

    printf("result: %d\n", result);

    return 0;
}