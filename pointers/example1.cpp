#include <iostream>

int main() {
    int a = 10;
    int *myptr = &a;

     // print the address stored in myptr pointer variable
    std::cout << "Address stored in myptr is: ";
    std::cout << myptr << std::endl;

    std::cout << "Adress of myptr is: ";
    std::cout << &myptr << std::endl;

    // printing value of a using pointer myptr
    std::cout << "Value of 'a' using *myptr is: ";
    std::cout << *myptr << std::endl;

    return 0;
}