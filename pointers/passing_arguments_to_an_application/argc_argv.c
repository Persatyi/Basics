/*
C supports command line arguments using the traditionally named argc and argv
parameters. The first parameter, argc, is an integer that indicates how many parameters
are passed. At least one parameter is always passed. This parameter is the name of the
executable. The second parameter, argv, is normally viewed as a one-dimensional
array of string pointers. Each pointer references a command line argument.
The following main function will simply list its arguments one per line. In this version,
argv is declared as a pointer to a pointer to a char:
*/
#include <stdio.h>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] %s\n", i, argv[i]);
    }
    return 0;
}

// The declaration of argv can be simplified as follows:
// int main(int argc, char* argv[]) 
