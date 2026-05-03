// Returning the Address of Dynamically Allocated Memory
#include <stdlib.h>

char *blanks(int number) {
    char *spaces = (char *)malloc(number + 1);
    int i;
    for (i = 0; i < number; i++) {
        spaces[i] = ' ';
    }
    spaces[number] = '\0';
    return spaces;
}