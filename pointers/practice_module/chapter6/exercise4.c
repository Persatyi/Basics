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

void initializeList(LinkedList *list) {
    list->current = NULL;
    list->head = NULL;
    list->tail = NULL;
}

void addHead(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL) {
        list->tail = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        node->next = list->head;
        node->prev = NULL;
        list->head->prev = node;
    }
    list->head = node;
}