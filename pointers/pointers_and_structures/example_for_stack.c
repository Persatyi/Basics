// Example from book for maintain stack
#include <stdlib.h>

typedef struct _node {
    void *data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

typedef LinkedList Stack;

void initializeList(LinkedList *list) {
    list->current = NULL;
    list->head = NULL;
    list->tail = NULL;
}

void addHead(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
}

void initializeStack(Stack *stack) {
    initializeList(stack);
}


// The push operation calls the addHead function as shown below:
void push(Stack *stack, void* data) {
 addHead(stack, data);
}


void *pop(Stack *stack) {
 Node *node = stack->head;
 if (node == NULL) {
 return NULL;
 } else if (node == stack->tail) {
 stack->head = stack->tail = NULL;
 void *data = node->data;
 free(node);
 return data;
 } else {
 stack->head = stack->head->next;
 void *data = node->data;
 free(node);
 return data;
 }
}