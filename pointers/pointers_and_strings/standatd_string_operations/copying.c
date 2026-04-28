// Copying strings is a common operation and is normally accomplished using the strcpy
// function whose prototype follows:
char *strcpy(char *s1, const char *s2);

/*
1. Read in the string using a large array of char
2. Use malloc to allocate just the right amount of memory
3. Use strcpy to copy the string into the dynamically allocated memory
*/
char name[32];
char *names[30];
size_t count = 0;

printf("Enter a name: ");
scanf("%s", name);
names[count] = (char *)malloc(strlen(name) + 1);
strcpy(names[count], name);
count++;

