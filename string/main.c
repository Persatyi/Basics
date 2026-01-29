#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    char *arr;

    printf("Enter number of characters to store: ");
    scanf("%d", &n); //getting size

    arr = (char *)malloc(n * sizeof(char));
    printf("Enter the string: ");

    for (i = 0; i < n; i++) {
        scanf(" %c", arr + i);
    }
    printf("\nThe string entered is: \n\n");

    for (i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\nThe element at index 2: %c ", arr[2]);

    return 0;
}