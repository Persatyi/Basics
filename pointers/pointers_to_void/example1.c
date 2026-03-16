// In the following code snippet, we declare
// and attempt to add one to the pointer:
#include <stdio.h>

int main() {
    int num = 5;
    void *pv = &num;
    printf("%p\n", pv);
    pv = pv + 1; // Syntax warning
    // Since this is not standard C, the compiler issued a warning. However, the resulting
    // address contained in pv will be incremented by four bytes.

    return 0;
}
