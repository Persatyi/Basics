/*
Strings can be allocated in several potential locations. The following example illustrates
possible variations:
*/
#include <stdlib.h>

char *globalHeader = "Chapter"; 
char globalArrayHeader[] = "Chapter";

void displayHeader() {
    static char *staticHeader = "Chapter";
    char *localHeader = "Chapter";
    static char staticArrayHeader[] = "Chapter";
    char localArrayHeader[] = "Chapter";
    char *heapHeader = (char *)malloc(strlen("Chapter") + 1);
    strcpy(heapHeader, "Chapter");
}