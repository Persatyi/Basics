/*
A compound literal is a C construct that consists of
what appears to be a cast operator followed by an initializer list enclosed in braces. An
example of a compound literal follows for both a constant integer and an array of inte‐
gers. These would be used as part of a declaration:
*/
// (const int){100};
// (int[3]){10, 20, 30};
/*
In the following declaration, we create the array arr1 by declaring it as an array of
pointers to an integer and using a block statement of compound literals to initialize it:
*/
int(*(arr1[])) = {
    (int[]){0, 1, 2},
    (int[]){3, 4, 5},
    (int[]){6, 7, 8},
};
// This array has three rows and three columns. The array’s elements are initialized with
// the value 0 through 8 in row column order
#include <stdio.h>

int main() {
    // The following sequence displays the addresses and values of each array element:
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            printf("arr1[%d][%d] Address: %p Value: %d\n", j, i, &arr1[j][i], arr1[j][i]);
        }
        printf("\n");
    }
        return 0;
}