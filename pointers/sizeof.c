#include <stdio.h>

// The sizeof operator can be used to determine the size of a pointer.


int main() {
    printf("Size of *char: %d\n", sizeof(char*));
    printf("Size of size_t: %zu\n", sizeof(size_t));
    printf("char: %zu\n", sizeof(char));
    printf("int: %zu\n", sizeof(int));
    printf("double: %zu\n", sizeof(double));
    printf("pointer: %zu\n", sizeof(int*));

    int arr[] = {10, 20, 30, 40, 50};
    size_t size = sizeof(arr);
    size_t element = sizeof(arr[0]);

    size_t count = size / element;

    printf("array bytes: %zu\n", size);
    printf("elements: %zu\n", count);

    for (size_t i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }

    char str[] = "hello";
    printf("sizeof: %zu\n", sizeof(str));

    // Безкінечний цикл бо size_t unsigned і коли ми декркментуємо 0 - 1; то відбувається unsigned overflow → дуже велике число.
    // тому правильно i > 0; чи int i = 5; i >= 0; i--
    // for (size_t i = 5; i >= 0; i--) { 
    //     printf("%zu\n", i);
    // }

        return 0;
}