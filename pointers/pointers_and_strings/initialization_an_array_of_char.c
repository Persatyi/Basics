/*
An array of char can be initialized using the initialization operator. In the following
example, a header array is initialized to the character contained in a string literal:
*/
char header[] = "Media Player";
/*
Since the literal “Media Player” is 12 characters in length, 13 bytes are required to rep‐
resent the literal. The array is allocated 13 bytes to hold the string. The initialization will
copy these characters to the array terminated by the NUL character.
*/

/*
An array can also be initialized using strcpy function. In the following sequence, the string literal is
copied to the array.
*/

char header1[13];
strcpy(header1, "Media Player");

// The following assignment is invalid. We cannot assign the address of a
// string literal to an array name.

char header2[];
header2 = "Media Player";
