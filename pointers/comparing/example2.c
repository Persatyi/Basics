#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

typedef int (*fptrOperation)(int, int);

// The add function is assigned to the fptr1 function pointer and then compared against the add function’s
// address:


int main() {
    fptrOperation fptr = add;
    if(fptr == add) {
        printf("fptr points to add function\n");
    } else {
        printf("fptr does not point to add function\n");
    }

    return 0;
}