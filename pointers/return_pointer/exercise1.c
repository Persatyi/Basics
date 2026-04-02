/*
Напиши функцію createString яка приймає рядок, виділяє для нього пам'ять через malloc,
копіює рядок і повертає вказівник. В main виклич функцію, виведи результат і не забудь про пам'ять.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createString(char *str) {
    char *tmp = (char *)malloc(strlen(str) + 1);
    if(tmp == NULL) {
        return NULL;
    }
    strcpy(tmp, str);

    return tmp;
}

int main() {
    char *ch = createString("Hello");
    printf("%s\n", ch);
    free(ch);
    ch = NULL;

    return 0;
}

