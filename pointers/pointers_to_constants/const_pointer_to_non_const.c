#include <stdio.h>

int num = 10;
int limit = 500;
int *const cpi = &num;

// Once an address has been assigned to cpi, we cannot assign a new value to cpi as shown
// below:
// int num2;
// int age;
// int *const cpi = &num2;
// cpi = &age; // 'cpi' : you cannot assign to a variable that is const

int main() {
// pointer to (constant pointer to constant)
  const int limit = 500;
  const int * const cpci = &limit;
 
  printf("%d\n",*cpci);
  const int * const * pcpci = &cpci;
  printf("%d\n",**pcpci);


  return 0;
}
