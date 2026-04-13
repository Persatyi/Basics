#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char *phrase) {
    char *begin = phrase;
    char *end = phrase;
    char *new = phrase;

      // перевіряємо чи є пробіли на початку рядку
    while (*begin == ' ') {
        begin++;
    }

    // йдемо в кінець рядку
    while(*end != '\0') {
        end++;
    }
    end--;
    
    // перевіряємо чи є пробіли в кінці рядку
    while (*end == ' ') {
        end--;
    }
    end++; // повертаємося на одну позицію вперед, щоб додати нуль термінатор
    *end = 0;

  

    while(*new) {
        *(new++) = *(begin++);
    }

    return (char *)realloc(phrase, strlen(phrase) + 1);
}

int main(){
    char *buffer = (char *)malloc(strlen(" cat ") + 1);
    strcpy(buffer, " cat ");
    buffer = trim(buffer);
    printf("%s\n", buffer);

    free(buffer);
    buffer = NULL;

    return 0;
}