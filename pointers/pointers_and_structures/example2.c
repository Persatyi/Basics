#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define LIST_SIZE 10


typedef struct _person {
    char* firstName;
    char* lastName;
    char* title;
    int age;
} Person;

Person *list[LIST_SIZE];

// Before the list can be used, it needs to be initialized. The following function assigns NULL
// to each element of the array:

void initializeList() {
    for (int i = 0; i < LIST_SIZE; i ++) {
        list[i] = NULL;
    }
}


void initializePerson(Person *person, const char* fn,
 const char* ln, const char* title, int age) {
 person->firstName = (char*) malloc(strlen(fn) + 1);
 strcpy(person->firstName, fn);
 person->lastName = (char*) malloc(strlen(ln) + 1);
 strcpy(person->lastName, ln);
 person->title = (char*) malloc(strlen(title) + 1);
 strcpy(person->title, title);
 person->age = age;
}

/*
This function retrieves a person from the list if possible. The array’s
elements are compared to NULL. The first non-null element is returned, and its position
in list is then assigned a value of NULL. If there is no person available, then a new
instance of a Person is created and returned. This avoids the overhead of dynamically
allocating memory for a person every time a new one is needed. We only allocate mem‐
ory if there is none in the pool.
*/

Person *getPerson() {
    for (int i = 0; i < LIST_SIZE; i++) {
        if(list[i] != NULL) {
            Person *ptr = list[i];
            list[i] = NULL;
            return ptr;
        }
    }
    Person *person = (Person *)malloc(sizeof(Person));
    return person;
}

void deallocatePerson(Person *person) {
 free(person->firstName);
 free(person->lastName);
 free(person->title);
}


Person *returnPerson(Person *person) {
    for (int i = 0; i < LIST_SIZE; i++) {
        if(list[i] == NULL) {
            list[i] = person;
            return person;
        }
    }
    deallocatePerson(person);
    free(person);
    return NULL;
}

void displayPerson(Person *person) {
    printf("First name: %s\n", person->firstName);
    printf("Last name: %s\n", person->lastName);
    printf("Title: %s\n", person->title);
    printf("Age: %d\n", person->age);
}


int main() {
    initializeList();
    Person *ptrPerson;

    ptrPerson = getPerson();
    initializePerson(ptrPerson,"Ralph","Fitsgerald","Mr.",35);
    displayPerson(ptrPerson);
    returnPerson(ptrPerson);
    return 0;
}