// In the first approach, we declare a structure using the struct keyword.
struct _person {
    char *firstName;
    char *lastName;
    char *title;
    unsigned int age;
};

//  In the second approach, we use a type definition.
// A structure’s declaration frequently uses the typedef keyword to simplify its use later
// in a program.

typedef struct _person {
    char *firstName;
    char *lastName;
    char *title;
    unsigned int age;
} Person;

// An instance of a person is declared as follows:

Person person;

// Alternately, we can declare a pointer to a Person and allocate memory for it, as shown
// below:

Person *ptrPerson;
ptrPerson = (Person *)malloc(sizeof(Person));

/*
If we use a simple declaration of a structure as we did with person, we use the dot
notation to access its fields. In the following example, we assign values to the first
Name and age fields:

Person person;

person.firstName = (char *)malloc(strlen("Emily") + 1);
strcpy(person.firstName, "Emily");
person.age = 23;
*/

/*
However, if we are using a pointer to a structure, we need to use the points-to operator,
as follows. This operator consists of a dash followed by the greater than symbol:
Person *ptrPerson;
ptrPerson = (Person *)malloc(sizeof(Person));
ptrPerson->firstName = (char *)malloc(strlen("Emily") + 1);
strcpy(ptrPerson->firstName, "Emily");
ptrPerson->age = 23;
*/

/*
We do not have to use the points-to operator. Instead, we can dereference the pointer
first and then apply the dot operator. This is illustrated below, where we duplicate the
previous assignments:
Person *ptrPerson;
ptrPerson = (Person *)malloc(sizeof(Person));
(*ptrPerson).firstName = (char *)malloc(strlen("Emily") + 1);
strcpy((*ptrPerson).firstName, "Emily");
(*ptrPerson).age = 23;
*/