// конкатенація без strcat
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void copyStr(char *dst, const char *src) {
    for (int i = 0; i < strlen(src); i++, dst++) {
        *dst = src[i];
    }
    *dst = '\0';
}

char *concatenate(const char *s1, const char *s2) {
    int size = strlen(s1) + strlen(s2) + 1;
    char *buffer = (char *)malloc(size);
    char *tmp = buffer;

    copyStr(tmp, s1);
    tmp += strlen(s1);
    copyStr(tmp, s2);

    return buffer;
}

int main() {
    char *str = concatenate("Hello ", "World!");
    printf("%s", str);
    free(str);
    str = NULL;

    return 0;
}