#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
It increments name by one with each loop iteration. At the end, name is left
pointing to the string’s NUL termination character. The allocated memory’s 
starting address has been lost.
*/

int main() {
    char *name = (char *)malloc(strlen("Susan") + 1);
    strcpy(name, "Susan");

    while(*name != 0) {
        printf("%c", *name);
        name++; // Losing an address
    }

    return 0;
}