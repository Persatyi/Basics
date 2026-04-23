/*
 Написати функцію яка збільшує масив з допомогою realloc
*/
#include <stdlib.h>

int *increaseArrSize(int *arr, int newSize) {
    int *tmp = (int *) realloc(arr, newSize * sizeof(int));
    if(tmp == NULL) {
        return NULL;
    }
    return tmp;
}

