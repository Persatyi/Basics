// In the following example, an attempt is made to allocate memory for 10 doubles:

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int AMOUNT_OF_DOUBLES = 10;
    double *ref = (double *)malloc(AMOUNT_OF_DOUBLES * sizeof *ref);

    
    printf("%d",sizeof *ref);
    free(ref);

    return 0;
}