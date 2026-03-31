/*
Passing Data by Value
If we do not pass them by pointers, then the swap operation will not occur. In the
following function, the two integers are passed by value:
*/
#include <stdio.h>

void swap(int num1, int num2) {
    int tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
}

int main() {
    int n1 = 5;
    int n2 = 10;
    swap(n1, n2);
    printf("n1: %d\n", n1);
    printf("n2: %d\n", n2);

    return 0;
}

/*
However, this will not work because the integers were passed by value and not by pointer.
Only a copy of the arguments is stored in num1 and num2. If we modify num1, then the
argument n1 is not changed. When we modify the parameters, we are not modifying
the original arguments. 
*/