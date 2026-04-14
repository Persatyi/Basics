// In the following example, an integer array is passed to a function along with its size. 
// Its contents are then displayed:
#include <stdio.h>

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i ++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int vector[5] = {1, 2, 3, 4, 5};
    displayArray(vector, 5);
    
    return 0;
}