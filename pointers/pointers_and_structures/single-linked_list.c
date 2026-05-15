#include <stdlib.h>

int compareEmployee(Employee *e1, Employee *e2) {
    return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee *employee) {
    printf("%s\t%d\n", employee->name, employee->age);
}

typedef void (*DISPLAY)(void *);
typedef int (*COMPARE)(void *, void *);

typedef struct _employee {
    char name[32];
    unsigned char age;
} Employee;

typedef struct _node {
    void *data;
    struct _node *next;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

/*
Before the linked list can be used it needs to be initialized. The initializeList function, 
shown below, performs this task. A pointer to the LinkedList object is passed to
the function where each pointer in the structure is set to NULL:
*/

void initializeList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

/*
Next, we check to see whether the linked list is empty. If so, we assign the tail pointer to
the node and assign NULL to the node’s next field. If not, the node’s next pointer is
assigned to the list’s head. Regardless, the list’s head is assigned to the node:
*/

void addHead(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
}

/*
The addTail function is shown below. It starts by allocating memory for a new node
and assigning the data to the data field. Since the node will always be added to the tail,
the node’s next field is assigned to NULL. If the linked list is empty, then the head pointer
will be NULL and head can be assigned to the new node. If it is not NULL, then the tail’s
next pointer is assigned to the new node. Regardless, the linked list’s tail pointer is
assigned to the node:
*/

void addTail(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(list->head = NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

/*
In the following sequence, the addTail function is illustrated. The creation of the em‐
ployee objects has not been duplicated here. The employees have been added in the
opposite order from the previous example using the addTail function.
initializeList(&linkedList);
 addTail(&linkedList, susan);
 addTail(&linkedList, sally);
 addTail(&linkedList, samuel);
*/

/*
The code for the getNode function follows. The variable node initially points to the list’s
head and traverses the list until either a match is found or the linked list’s end is en‐
countered. The compare function is invoked to determine whether a match is found.
When the two data items are equal, it returns a zero.
*/

Node *getNode(LinkedList *list, COMPARE compare, void *data) {
    Node *node = list->head;
    while(node != NULL) {
        if(compare(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/*
The following code sequence illustrates using the initializeList and addHead func‐
tions. Three employees are added to the list.
*/

int main() {
    LinkedList linkedList;
    Employee *samuel = (Employee *)malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;

    Employee *sally = (Employee *)malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;

    Employee *susan = (Employee *)malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    sally->age = 45;

    initializeList(&LinkedList);

    addHead(&linkedList, samuel);
    addHead(&linkedList, sally);
    addHead(&linkedList, susan);

    return 0;
}