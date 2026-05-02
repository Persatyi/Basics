/*
An example of returning a literal is shown below. An integer code selects from one of
four different processing centers. The function’s purpose is to return the processing
center’s name as a string. In this example, it simply returns the literal’s address:
*/
#include <stdio.h>

char *returnALiteral(int code) {
    switch(code){
        case 100:
          return "Boston Processing Center";
        case 200:
          return "Denver Processing Center";
        case 300:
          return "Atlanta Processing Center";
        case 400:
          return "San Jose Processing Center"; 
    }
}

/*
We can also declare static literals as in the following example. A subCode field has been
added and selects between different centers. The advantage of this approach is not hav‐
ing to use the same literal in more than one place and possibly introducing errors by
mistyping the literal:
*/
char *returnAStaticLiteral(int code, int subCode){
    static char* bpCenter = "Boston Processing Center";
    static char* dpCenter = "Denver Processing Center";
    static char* apCenter = "Atlanta Processing Center";
    static char* sjpCenter = "San Jose Processing Center";

    switch(code) {
        case 100:
            return bpCenter;
        case 135:
          if(subCode < 35) {
              return dpCenter;
          } else {
              return bpCenter;
          }
        case 200:
            return dpCenter;
        case 300:
            return apCenter;
        case 400:
            return sjpCenter;
    }
}

/*
Returning a pointer to a static string used for multiple purposes can be a problem.
Consider the following variation of the format function:
*/

char *staticFormat(const char *name, size_t quantity, size_t weight) {
    static char buffer[64]; // Assume to be large enough
    sprintf(buffer, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);
    return buffer;
}
/*
The buffer is allocated 64 bytes, which may or may not be enough. For purposes of this
example, we will ignore this potential problem. The main problem with this approach
is illustrated with the following sequence:
*/

int main() {
    char *part1 = staticFormat("Axle", 25, 45);
    char *part2 = staticFormat("Piston", 55, 5);
    printf("%s\n",part1);
    printf("%s\n", part2);
    /*
    When executed, we get the following output:
    Item: Piston Quantity: 55 Weight: 5
    Item: Piston Quantity: 55 Weight: 5
    Since the staticFormat method used the same static buffer for both calls, the last call
    overwrote the first call’s results.
    */
    return 0;
}