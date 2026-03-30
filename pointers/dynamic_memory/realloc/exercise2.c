/*
Створи динамічний рядок через malloc, скопіюй в нього слово, потім через realloc розшир щоб додати ще одне слово в кінець. Виведи результат.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *word = "Hello";
    char *str = (char *)malloc(strlen(word) + 1);
    if(str == NULL) {
        return 1;
    }
    strcpy(str, word);
    const char *word2 = "world!";
    char *str2 = (char *)realloc(str, ((strlen(word) + 1) + (strlen(word2) + 1)));

    if(str2 == NULL) {
        free(str);
        str = NULL;
        return 1;
    }

    strcat(str2, " ");
    strcat(str2, word2);

    printf("%s", str2);

    free(str2);
    str2 = NULL;
    str = NULL;

    return 0;
}