// Перевіряємо розміри 
#include <stdio.h>
#include <stdint.h>

int main() {
    printf("pointer: %zu\n", sizeof(void*)); // 8
    printf("uintptr_t: %zu\n", sizeof(uintptr_t)); // 8
    printf("intptr_t: %zu\n", sizeof(intptr_t)); // 8

    return 0;
}