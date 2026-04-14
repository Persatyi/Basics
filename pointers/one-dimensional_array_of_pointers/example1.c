/*
The following sequence declares an array of integer pointers, allocates
memory for each element, and initializes this memory to the array’s index:
*/
int *arr[5];
for (int i = 0; i < 5; i++) {
    arr[i] = (int *)malloc(sizeof(int));
    *arr[i] = i;
}
/*
We used arr[i] to reference the pointer and *arr[i] to assign a value to the location referenced by the
pointer. Do not let the use of array notation confuse you. Since arr was declared as an
array of pointers, arr[i] returns an address. When we dereference a pointer such as
*arr[i], we get the contents at that address.
*/

// We could have used the following equivalent pointer notation for the loop’s body:
*(arr + i) = (int *)malloc(sizeof(int));
**(arr + i) = i;