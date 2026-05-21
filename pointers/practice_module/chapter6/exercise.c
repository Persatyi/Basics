// double-linked list

typedef struct _node {
    struct _node *next;
    struct _node *prev;
    void *data;
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
}