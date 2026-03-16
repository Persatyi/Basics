// If a pointer is declared as global or static, it is initialized to NULL when the program starts.
int *plobalpi;

void foo() {
    static int *staticpi;
}