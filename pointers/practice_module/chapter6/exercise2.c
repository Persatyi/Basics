// практика написання зв'язних списків
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    struct _node *next;
    void *data;
} Node;

typedef struct _linkedList {
    Node *head;
} LinkedList;

void initializeList(LinkedList *list) {
    list->head = NULL;
}

void addHead(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL) {
        list->head = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
}

void displayList(LinkedList *list) {
    Node *tmp = list->head;
    while(tmp != NULL) {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

void freeList(LinkedList *list) {
    Node *tmp = list->head;
    while(tmp != NULL) {
        list->head = tmp->next;
        free(tmp);
        tmp = list->head;
    }
}

int main() {
    LinkedList list;
    initializeList(&list);
    addHead(&list, "Peter");
    addHead(&list, "Sarah");
    displayList(&list);
    freeList(&list);
    return 0;
}