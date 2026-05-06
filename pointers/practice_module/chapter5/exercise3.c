// напиши функцію яка порівнює два рядки без strcmp
int compare(char *s1, char *s2) {
    while(*s1 && *s2 && *s1 == *s2) {
            s1++;
            s2++;
    }

    return *s1 - *s2;
}