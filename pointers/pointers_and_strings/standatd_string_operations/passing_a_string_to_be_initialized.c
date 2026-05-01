#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
The snprintf function was used as a simple way of formatting the string. This function
writes to the buffer provided by the first parameter. The second argument specifies the
buffer’s size. This function will not write past the end of the buffer. Otherwise, the
function behaves the same way as printf.
*/
char *format(char *buffer, size_t size, const char* name, size_t quantity, size_t weight) {
    snprintf(buffer, size, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);

    return buffer;
}
/*
An alternative to this approach is to pass NULL as the buffer’s address. This implies the
caller does not want to provide the buffer or is unsure how large the buffer should be.
This version of the function can be implemented as follows. When length is calculated
the subexpression 10 + 10 represents the largest width anticipated for the quantity and
weight. The one allows space for the NUL termination character:
*/
char *format2(char *buffer, size_t size, const char *name, size_t quantity, size_t weight) {
    char *formatString = "Item: %s Quantity: %u Weight: %u";
    size_t formatStringLength = strlen(formatString) - 6; //тут 6 бо специфікатори %s %u займають 6 знаків
    size_t nameLength = strlen(name);
    size_t length = formatStringLength + nameLength + 10 + 10 + 1; // тут 10 + 10 + 1 тому що 10 це максимальна очікувана ширина числа а 1 це нуль термінатор

    if(buffer == NULL) {
        buffer = (char *)malloc(length);
        size = length;
    }

    snprintf(buffer, size, formatString, name, quantity, weight);

    return buffer;
}
/*
The function variation to use depends on the needs of the application. The chief draw‐
back of the second approach is that the caller is now responsible for freeing the memory
allocated. The caller needs to be fully aware of how this function should be used; other‐
wise, a memory leak can easily occur.
*/


int main() {
    const int size = 64;
    char *buffer = (char *)malloc(size);
    printf("%s\n", format(buffer, size, "Axle", 25, 45));
    free(buffer);
    buffer = NULL;

    char *buffer2 = format2(NULL, 0, "Axle", 25, 45);
    printf("%s", buffer2);
    free(buffer2);
    buffer2 = NULL;

    return 0;
}