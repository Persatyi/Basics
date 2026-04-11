#include <stdio.h>

int main() {
    int vector[5] = {1, 2, 3, 4, 5};
    int *pv = vector;
    printf("%p\n",vector);
    printf("%p\n", &vector[0]);

    return 0;
}

