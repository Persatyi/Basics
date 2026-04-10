/*
Виділи масив з 5 інтів через calloc, виведи всі елементи (перевір що вони 0), потім звільни пам'ять правильно.
*/
#include <stdlib.h>
#include <stdio.h>

int main() {
    int *arr = calloc(5, sizeof *arr);
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    free(arr);
    arr = NULL;
    
    return 0;
}