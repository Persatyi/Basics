#include <stdio.h>
#include <stdint.h>

int main() {
    int arr[3] = {1, 2, 3};

    uintptr_t a = (uintptr_t)&arr[0];
    uintptr_t b = (uintptr_t)&arr[1];

    printf("sizeof int: %d\n", sizeof(int));
    printf("a: %zu\n", a);
    printf("Size of a: %d\n", sizeof(a));
    printf("b: %zu\n", b);
    printf("Size of b: %d\n", sizeof(b));
    printf("%zu\n", b - a);

    return 0;
}