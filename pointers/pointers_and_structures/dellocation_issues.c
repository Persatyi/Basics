/*
When memory is allocated for a structure, the runtime system will not automatically
allocate memory for any pointers defined within it. Likewise, when the structure goes
away, the runtime system will not automatically deallocate memory assigned to the
structure’s pointers.
*/

typedef struct _person {
    char *firstName;
    char *lastName;
    char *title;
    uint age;
} Person;

// When we declare a variable of this type or dynamically allocate memory for this type,
// the three pointers will contain garbage.

void initializePerson(Person *person, const char *fn, const char *ln, const char *title, uint age) {
    person->firstName = (char *)malloc(strlen(fn) + 1);
    strcpy(person->firstName, fn);
    person->lastName = (char *)malloc(strlen(ln) + 1);
    strcpy(person->lastName, ln);
    person->title = (char *)malloc(sizeof(title) + 1);
    strcpy(person->title, title);
    person->age = age;
}

// We can use this function as shown below
void processPerson() {
    Person person;
    initializePerson(&person, "Peter", "Underwood", "Manager", 36) {

    }
    deallocatePerson(&person);
}

/*
When we are through with the instance, we need to deallocate the memory. The fol‐
lowing function will free up the memory we previously allocated when we created the
instance:
*/

void deallocatePerson(Person *person) {
    free(person->firstName);
    free(person->lastName);
    free(person->title);
}

/*
If we use a pointer to a Person, we need to remember to free up the person as shown
below:
*/

void processPerson() {
 Person *ptrPerson;
 ptrPerson = (Person*) malloc(sizeof(Person));
 initializePerson(ptrPerson, "Peter", "Underwood", "Manager", 36);
 ...
 deallocatePerson(ptrPerson);
 free(ptrPerson);
}
