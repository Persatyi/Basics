/*
String concatenation involves the merging of two strings. The strcat function is fre‐
quently used for this operation. This function takes pointers to the two strings to be
concatenated and returns a pointer to the concatenated results. The prototype for the
function follows:
*/
char *strcat(char *s1, const char *s2);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *error = "Error: ";
    char *errorMessage = "Not enough memory";

    char *buffer = (char *)malloc(strlen(error) + strlen(errorMessage) + 1);
    strcpy(buffer, error);
    strcat(buffer, errorMessage);

    printf("%s\n", buffer);
    printf("%s\n", error);
    printf("%s\n", errorMessage);

    free(buffer);
    buffer = NULL;

    return 0;
}