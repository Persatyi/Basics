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

// void addHead(LinkedList *list, void *data) {
//     Node *node = (Node *)malloc(sizeof(Node));
//     node->data = data;
//    if(list->head == NULL) {
//        list->tail = node;
//        node->next = NULL;
//    } else {
//        node->next = list->head;
//    }
//    list->head = node;
// }

// addHead for Double_Linked List
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

void addTail (LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

Node *getNode(LinkedList *list, COMPARE compare, void *data) {
    Node *node = list->head;
    while (node != NULL) {
        if(compare(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void delete(LinkedList *list, Node *node){
    if(node == list->head) {
        if(list->head->next == NULL) {
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        Node *tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if(tmp != NULL) {
            tmp->next = node->next;
        }
    }
    free(node);
    node = NULL;
}