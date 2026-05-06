// напиши функцію яка копіює рядок без strcpy
#include <stdlib.h>

char *strCopy(char *str) {
    char *buffer = (char *)malloc(strlen(str) + 1);
    char *tmp = buffer;
    while(*str) {
        *(tmp++) = *str;
        str++;
    }

    *tmp = '\0';

    return buffer;
}