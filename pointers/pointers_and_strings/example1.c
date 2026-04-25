/*
In most compilers, a string literal is treated as a constant. It is not possible to modify
the string. However, in some compilers, such as GCC, modification of the string literal
is possible. Consider the following example:
*/

#include <stdio.h>

int main(){
    char *tabHeader = "Sound";
    *tabHeader = 'L';
    printf("%s\n", tabHeader);

    return 0;
}