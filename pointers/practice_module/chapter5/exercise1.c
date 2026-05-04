//  напиши функцію яка приймає рядок і повертає його довжину без використання strlen.
size_t strSize(char *str) {
    size_t size = 0;
    while(*(str++)) {
        size++;
    }
    return size;
}

