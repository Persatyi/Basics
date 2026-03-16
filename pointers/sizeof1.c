#include <stdio.h>

int main() {
    int arr[] = {3,7,2,9,5};
    size_t count = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (size_t i = 0; i < count; i++) {
        sum += arr[i];
        printf("%d\n", arr[i]);
    }
    printf("Sum of all elements: %d", sum);

    return 0;
}