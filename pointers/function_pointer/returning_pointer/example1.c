/*
We will use the following select function to return a function pointer to an operation
based in a character input. It will return a pointer to either the add function or the
subtract function, depending on the opcode passed:
*/

#include <stdio.h>

int add(int num1, int num2) {
    return num1 + num2;
}

int substruct(int num1, int num2) {
    return num1 - num2;
}

typedef int (*fptrOperation)(int, int);

fptrOperation select(char opcode) {
    switch(opcode) {
        case '+':
            return add;
        case '-':
            return substruct;
    }
}

/*
The evaluate function ties these functions together. The function is passed two integers
and a character representing the operation to be performed. It passes the opcode to the
select function, which returns a pointer to the function to execute. In the return state‐
ment, it executes this function and returns the result:
*/

int evaluate(char opcode, int num1, int num2) {
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}

int main() {
    printf("%d\n", evaluate('+', 5, 6));
    printf("%d\n", evaluate('-', 5, 6));

    return 0;
}