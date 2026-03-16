#include <stdint.h>
#include <stdio.h>

int main() {
    int x = 10;

    int *p = &x;
    uintptr_t addr = (uintptr_t)p;

    printf("pointer: %p\n", p);
    printf("as integer: %zu\n", addr);

    // І можна зробити назад
    int *p2 = (int *)addr;
    printf("pointer: %p\n", p);

    return 0;
}

