/*
There are several ways of passing the address of a string to a function, depending on
how the string is declared. In this section, we will demonstrate these techniques using
a function that mimics the strlen function as implemented below. We used parentheses
to force the post increment operator to execute first, incrementing the pointer.
Otherwise, the character referenced by string would have been incremented, which is
not what is desired:
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t stringLength(char *string) {
    size_t length = 0;
    while(*(string++)) {
        length++;
    }
    return length;
}

int main() {
    // Let’s start with the following declarations:
    char simpleArray[] = "simple string";
    char *simplePtr = (char *)malloc(strlen("simple string") + 1);
    strcpy(simplePtr, "simple string");
    printf("%d\n", stringLength(simplePtr));
    free(simplePtr);
    simplePtr = NULL;
    /*
    To invoke the function using the array, we have three choices, as shown below. In the
    first statement, we use the array’s name. This will return its address. In the second
    statement, the address-of operator is used explicitly. This is redundant and unnecessary.
    In addition, it will often generate a warning. In the third statement, we used the address of 
    operator with the array’s first element. While this works, it is somewhat verbose:
    */
    printf("%d\n", stringLength(simpleArray));
    // printf("%d\n", stringLength(&simpleArray));
    printf("%d\n", stringLength(&simpleArray[0]));

    return 0;
}
