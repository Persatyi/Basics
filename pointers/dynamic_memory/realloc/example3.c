/*
The realloc function can also be used to decrease the amount of space used by a pointer.
To illustrate its use, the trim function shown below will remove leading blanks in a
string:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *trim(char *phrase) { // Оголошуємо функцію яка повертає вказівник типу char
    char *old = phrase; 
    char *new = phrase;

    while(*old == ' ') { // тут цикл зміщує адресу поки не наткнеться на пробіл
        old++;
    }

    while(*old) { // тут присвоюється значення після пробілу поки цикл не наткнеться на нуль темінатор
        *(new++) = *(old++);
    }
    *new = 0; // це не зрозуміло для чого
    return (char *)realloc(phrase, strlen(phrase) + 1); // повертаємо посилання на новий розмір
}

int main() {
    char *buffer = (char *)malloc(strlen(" cat") + 1); // виділяємо пам'ять
    strcpy(buffer, " cat"); // копіюємо в buffer стрічку
    buffer = trim(buffer);
    printf("%s\n", buffer); // ага зрозумів функція прибирає пробіли

    free(buffer);
    buffer = NULL;

    return 0;
}