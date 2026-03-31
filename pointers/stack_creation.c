/*
When executed, you get output similar to the following:
arr: 0x500
size: 0x504
sum: 0x480
The gap in the addresses between the parameters and the local variables is due to other
elements of the stack frame used by the runtime system to manage the stack.
When the stack frame is created, the parameters are pushed onto the frame in the op‐
posite order of their declaration, followed by the local variables.
*/

#include <stdio.h>

float average(int *arr, int size) {
    int sum;
    printf("arr: %p\n", &arr);
    printf("size: %p\n", &size);
    printf("sum: %p\n", &sum);

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return (sum + 1.0f) / size;
}

int main() {
    int arr[4];
    average(arr, 4);
    return 0;
}