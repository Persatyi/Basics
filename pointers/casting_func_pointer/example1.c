#include <stdio.h>

typedef int (*fptrToSingleInt)(int);
typedef int (*fptrToTwoInts)(int, int);

int add(int, int);

int add(int a, int b) {
    return a + b;
}

int main() {
    fptrToTwoInts fptrFirst = add;
    fptrToSingleInt fptrSecond = (fptrToSingleInt)fptrFirst;
    fptrFirst = (fptrToTwoInts)fptrSecond;
    printf("%d\n", fptrFirst(5, 6));

    return 0;
}