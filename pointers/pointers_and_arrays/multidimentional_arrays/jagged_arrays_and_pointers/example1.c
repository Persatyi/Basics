int(*(arr2[])) = {
    (int[]){0, 1, 2, 3},
    (int[]){4, 5},
    (int[]){6, 7, 8},
};
/*
We used three compound literals to declare the jagged array. The array’s elements are
initialized in row-column order starting with a value of zero. The next sequence will
display the array to verify its creation. The sequence required three for loops because
each row had a different number of columns:

*/
#include <stdio.h>

int main() {
    int row = 0;
    for (int i = 0; i < 4; i++) {
        printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i], arr2[row][i]);
    }
    printf("\n");

    row = 1;
    for (int i = 0; i < 2; i++) {
        printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i], arr2[row][i]);
    }
    printf("\n");

    row = 2;
    for (int i = 0; i < 3; i++) {
        printf("layer1[%d][%d] Address: %p Value: %d\n", row, i, &arr2[row][i], arr2[row][i]);
    }
    printf("\n");

    return 0;
}