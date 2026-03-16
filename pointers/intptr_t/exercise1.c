#include <stdio.h>
#include <stdint.h>

int main() {
    int x = 42;
    int *p = &x;

    uintptr_t addr = (uintptr_t)p;
    int *p2 = (int *)addr;

    printf("%d\n", *p2);

    return 0;
}   