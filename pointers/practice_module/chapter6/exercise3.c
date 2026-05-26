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

void delete(LinkedList *list, Node *node){
    if(node == list->head) {
        
    }
}