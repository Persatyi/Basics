/*
Оголоси структуру Person з полями name (масив 50 символів) і age (int). 
Створи одну змінну цієї структури через malloc, обнули її через memset, 
і виведи age щоб переконатись що він дорівнює 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
     Person *a = (Person *) malloc(sizeof *a);
    if(a == NULL) {
        return 1;
    }

    printf("%zu", sizeof *a);

    memset(a, 0, sizeof *a);

    printf("Age: %d", a->age);

    free(a);

    return 0;
}