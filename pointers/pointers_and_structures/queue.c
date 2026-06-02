#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

// We can now use Queue to clearly designate our intent:
typedef LinkedList Queue;

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

void initializeList(LinkedList *list) {
    list->current = NULL;
    list->head = NULL;
    list->tail = NULL;
}

/*
To implement the initialization operation, all we need to do is use the function
initializeList. Instead of calling this function directly, we will use the following
initializeQueue function:
*/
void initializeQueue(Queue *queue) {
    initializeList(queue);
}

// In a similar manner, the following will add a node to a queue using the addHead function:

void enqueue(Queue *queue, void *node) {
    addHead(queue, node);
}

/*
The previous linked list implementation does not have an explicit function to remove
the tail node. The dequeue function that follows removes the last node. Three conditions
are handled:
An empty queue
NULL is returned
A single node queue
Handled by the else if statement
A multiple node queue
Handled by the else clause

In the latter case, the tmp pointer is advanced node by node until it points to the node
immediately preceding the tail node. Three operations are then performed in the fol‐
lowing sequence:
1. The tail is assigned to the tmp node
2. The tmp pointer is advanced to the next node
3. The tail’s next field is set to NULL to indicate there are no more nodes in the queue
*/

void *dequeue(Queue *queue) {
    Node *tmp = queue->head;
    void *data;
    if(queue->head == NULL) {
        data = NULL;
    } else if(queue->head == queue->tail) {
        queue->head = queue->tail = NULL;
        data = tmp->data;
        free(tmp);
    } else {
        while(tmp->next != queue->tail) {
            tmp = tmp->next;
        }
        queue->tail = tmp;
        tmp = tmp->next;
        queue->tail->next = NULL;
        data = tmp->data;
        free(tmp);
    }
    return data;
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    Employee *samuel = (Employee *)malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 28;

    Employee *sally = (Employee *)malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;

    Employee *susan = (Employee *)malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;

    enqueue(&queue, samuel);
    enqueue(&queue, sally);
    enqueue(&queue, susan);

    void *data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee*) data)->name);
    data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee*) data)->name);
    data = dequeue(&queue);
    printf("Dequeued %s\n", ((Employee*) data)->name);

    return 0;
}