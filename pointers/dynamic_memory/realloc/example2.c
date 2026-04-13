/*
To illustrate the realloc function, we will implement a function to read in characters
from standard input and assign them to a buffer. The buffer will contain all of the
characters read in except for a terminating return character. Since we do not know how
many characters the user will input, we do not know how long the buffer should be. We
will use the realloc function to allocate additional space by a fixed increment amount.
The code to implement this function is shown below:
*/

#include <stdio.h>
#include <stdlib.h>

char* getLine() { // оголошуємо фнкцію яка повертає вказвник типу char
    const size_t sizeIncrement = 10; // оголошуємо константу типу size_t і задаємо значення 10
    char *buffer = malloc(sizeIncrement); // оголошуємо вказівник і типу char і виділяємо 10 байтів
    char *currentPosition = buffer; // оголошуємо ще один вказівник типу char і присвоюємо йому адресу попереднього вказівника
                                    // (по ідеї він буде використовуватися для подальшого інкрементування)
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;

    if(currentPosition == NULL) {
        return NULL;
    }

    while(1) {
        character = fgetc(stdin); // fgetc(stdin зчитує значення з клавіатури і повертає unsigned char конвертований в int
        if(character == '\n') {
            break;
        }

        if(++length >= maximumLength) { // якщо рядок довше ніж 10 символів то виділяємо ще 10 байтів
            char *newBuffer = realloc(buffer, maximumLength += sizeIncrement); // виділяємо додатково 10 байтів до старого масиву

            if(newBuffer == NULL) {
                free(buffer);
                return NULL;
            }

            currentPosition = newBuffer + (currentPosition - buffer); // додаємо кількість позицій зі старого масиву до нового
                                                                      // і отримуємо позицію для продовження
            buffer = newBuffer; // перевизначаємо початкову адресу нового масиву
        }
        *currentPosition++ = character; // записуємо значення до комірки й інкрементуємо адресу, щоб вона вказувала на наступну комірку
    }
    *currentPosition = '\0'; // нуль термінатор для позначення кінця рядка
    return buffer;
}

int main() {
   char *str = getLine();
   printf("%s", str);
   free(str);
   str = NULL;

   return 0;
}