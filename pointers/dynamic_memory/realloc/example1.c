/*
The heap manager was able to reuse the original block, and it did not modify its contents.
However, the program continued to use more than the eight bytes requested. That is,
we did not change the string to fit into the eight-byte block. In this example, we should
have adjusted the length of the string so that it fits into the eight reallocated bytes. The
simplest way of doing this is to assign a NUL character to address 507. Using more space
than allocated is not a good practice and should be avoided.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() {
    char *string1;
    char *string2;
    string1 = (char *)malloc(16);
    strcpy(string1, "0123456789AB");

    string2 = realloc(string1, 8);
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);

    free(string2); // звільняємо перед наступним malloc
    string2 = NULL;
    string1 = NULL; // string1 вже невалідний після realloc

    // In this next example, we will reallocate additional memory:

    string1 = (char *)malloc(16);
    strcpy(string1, "0123456789AB");
    string2 = realloc(string1, 64);
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);


    free(string2);
    string2 = NULL;
    string1 = NULL;

    return 0;
}