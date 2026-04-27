// The standard way to compare strings is to use the strcmp function. Its prototype follows:
int strcmp(const char *s1, const char *s2);

/*
The positive and negative return values are useful for sorting strings in alphabetical
order. The use of this function to test equality is illustrated below. The user’s entry will
be stored in command. This is then compared to the literal string:
*/
#include <stdio.h>

int main() {
    char command[16];
    printf("Enter a Command: ");
    scanf("%s", command);
    if(strcmp(command, "Quit") == 0) {
        printf("The command was Quit");
    } else {
        printf("The command was not Quit");
    }
    return 0;
}