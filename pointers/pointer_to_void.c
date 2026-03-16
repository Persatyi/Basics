#include <stdio.h>
// An example of a pointer to void is shown below:
// void *pv;


int main() {
// int num;
// int *pi = &num;
// printf("Value of pi: %p\n", pi);
// void *pv = pi;
// pi = (int *)pv;
// printf("Value of pi: %p\n", pi);

int num = 10;

int *pi = &num;
void *pv = pi;
char *pc = pv;

printf("pi: %p\n", pi);
printf("pv: %p\n", pv);
printf("pc: %p\n", pc);

return 0;
}
