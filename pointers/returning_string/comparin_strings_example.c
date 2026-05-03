#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
The comparison functions we will use determine the sorting order based on the case of
the array’s elements. The following two functions, compare and compareIgnoreCase,
compare two strings based on the case of the strings.
*/

int compare(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

char *stringToLower(const char *string) {
    char *tmp = (char *)malloc(strlen(string) + 1);
    char *start = tmp;
    while(*string != 0) {
        *tmp++ = tolower(*string++);
    }
    *tmp = 0;
    return start;
}

typedef int(ftpOperation)(const char *, const char *);

int compareIgnoreCase(const char *s1, const char *s2) {
    char *t1 = stringToLower(s1);
    char *t2 = stringToLower(s2);
    int result = strcmp(t1, t2);
    free(t1);
    free(t2);
    return result;
}

/*
The following sort function’s implementation is based on the bubble sort algorithm. It
is passed the array’s address, its size, and a pointer to the function controlling the sort.
In the if statement, the function passed is invoked with two elements of the array. It
determines whether the array’s two elements will be swapped.
*/
void sort(char *array[], int size, ftpOperation operation) {
    int swap = 1;
    while(swap) {
        swap = 0;
        for (int i = 0; i < size - 1; i++) {
            if(operation(array[i], array[i + 1]) > 0) {
                swap = 1;
                char *tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
            }
        }
    }
}

// A display function will show the array’s contents:
void displayNames(char* names[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s   ", names[i]);
    }
    printf("\n");
}

int main() {
    char *names[] = {"Bob", "Ted", "Carol", "Alice", "alice"};
    sort(names, 5, compare);
    displayNames(names, 5);
    // If we had used the compareIgnoreCase function instead, then our output would appear
    // as shown below:
    // Alice alice Bob Carol Ted
    sort(names, 5, compareIgnoreCase);
    displayNames(names, 5);

    return 0;
}