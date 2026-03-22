// Since the malloc function may return a NULL value if it is unable to
// allocate memory, it is a good practice to check for a NULL value before
// using the pointer as follows:

int *pi = (int *)malloc(sizeof(int));
if(pi != NULL) {
    // Pointer should be good
} else {
    // Bad pointer
}