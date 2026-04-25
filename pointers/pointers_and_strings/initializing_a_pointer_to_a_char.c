/*
Using dynamic memory allocation provides flexibility and potentially allows the
memory to stay around longer. The following declaration will be used to illustrate this
technique:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /*
    A common way to initialize this string is to use the malloc and strcpy functions to
    allocate and copy a literal to the string, as illustrated below:
    */
    char *header = (char *)malloc(strlen("Media Player") + 1);
    strcpy(header, "Media Player");

    /*
    The address of a string literal can be assigned directly to a character pointer as shown
    below. However, this does not create a new copy of the string.

    char *header = "Media Player";
    */

   /*
   Attempting to initialize a pointer to a char with a character literal will
    not work. Since a character literal is of type int, we would be trying to
    assign an integer to a character pointer. This will frequently cause the
    application to terminate when the pointer is dereferenced:

    char *prefix = '+'; // Illegal

    A valid approach using the malloc function follows:
   */
    char *prefix = (char *)malloc(2);
    *prefix = '+';
    *(prefix + 1) = 0;

    return 0;
}