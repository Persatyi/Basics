/*
Arrays of function pointers can be used to select the function to evaluate on the basis
of some criteria. Declaring such an array is straightforward. We simply use the function
pointer declaration as the array’s type, as shown below. The array is also initialized to
all NULLs. When a block of initialization values are used with an array, its values will be
assigned to consecutive elements of the array. If the number of values is less than the
size of the array, as in this example, the value is used to initialize every element of the
array:
*/
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int substruct(int a, int b) {
    return a - b;
}

typedef int (*operation)(int, int);
operation operations[128] = {NULL};

// Alternatively, we can declare this array without using a typedef as shown below:
//  int(*operations[128])(int, int) = {NULL};

// Having initialized the array to all NULLs, we then assign the add and subtract functions
// to the elements corresponding to the plus and minus signs:
void initializeOperationsArray() {
    operations['+'] = add;
    operations['-'] = substruct;
}

// The previous evaluate function is rewritten as evaluateArray. Instead of calling the
// select function to obtain a function pointer, we used the operations with the operation
// character as an index:

int evaluateArray(char opcode, int num1, int num2) {
    operation fptr = operations[opcode];
    if(fptr != NULL) {
        return fptr(num1, num2);
    }
    return -1;
}


int main() {
    initializeOperationsArray();
    printf("%d\n", evaluateArray('+', 5, 6));
    printf("%d\n", evaluateArray('-', 5, 6));
    return 0;
}