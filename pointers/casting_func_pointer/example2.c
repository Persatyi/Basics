#include <stdio.h>

typedef void (*fptrBase)();
typedef int (*fptrToSingleInt)(int);
typedef int (*fptrToTwoInts)(int, int);

int add(int, int);

int add(int a, int b) {
    return a + b;
}

int main() {
    fptrBase basePointer;
    fptrToTwoInts fptrFirst = add;
    basePointer = (fptrBase)fptrFirst;
    fptrFirst = (fptrToTwoInts)basePointer;
    printf("%d\n", fptrFirst(5, 6));

    return 0;
}