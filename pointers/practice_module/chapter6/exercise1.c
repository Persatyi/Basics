// задача з використанням linked list
#include <stdlib.h>
#include <stdio.h>

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

void freeList(LinkedList *list){
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
    addHead(&list, "Sarah");
    addHead(&list, "Tom");
    addHead(&list, "Susan");
    displayList(&list);
    freeList(&list);

    return 0;
}