#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Pointers provide an obvious and dynamic way of maintaining the relationship between
tree nodes. Nodes can be dynamically allocated and added to a tree as needed. We will
use the following structure for a node. Using a pointer to void allows us to handle any
type of data that we need:
*/

typedef struct _employee {
    char name[32];
    unsigned char age;
} Employee;

int compareEmployee(Employee *e1, Employee *e2) {
    return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee *employee) {
    printf("%s\t%d\n", employee->name, employee->age);
}

typedef int (*COMPARE)(void *, void *);
typedef void (*DISPLAY)(void *);

typedef struct _tree {
    void *data;
    struct _tree *left;
    struct _tree *right;
} TreeNode;

/*
The following insertNode function will insert a node into a binary search tree. However,
to insert a node, a comparison needs to be performed between the new node and the
tree’s existing nodes. We use the COMPARE function pointer to pass the comparison func‐
tion’s address. The first part of the function allocates memory for a new node and assigns
the data to the node. The left and right children are set to NULL since new nodes are
always added as leaves to a tree:
*/

void insertNode(TreeNode **root, COMPARE compare, void *data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL) {
        *root = node;
        return;
    }

    while(1) {
        if(compare((*root)->data, data) > 0) {
            if((*root)->left != NULL) {
                *root = (*root)->left;
            } else {
                (*root)->left = node;
                break;
            }
        } else {
            if((*root)->right != NULL) {
                *root = (*root)->right;
            } else {
                (*root)->right = node;
                break;
            }
        }
    }
}

/*
Binary trees are used for a number of purposes and can be traversed in three different
ways: pre-order, in-order, and post-order. The three techniques use the same steps, but
they are performed in different orders. The three steps are:
Visit the node
    Process the node
Go left
    Transfer to the left node
Go right
    Transfer to the right node

For our purposes, visiting a node means we will display its contents. The three orders
are:
In-order
Go left, visit the node, go right
Pre-order
Visit the node, go left, go right
Post-order
Go left, go right, visit the node

The functions’ implementations are shown below. Each passes the tree’s root and a
function pointer for the display function. They are recursive and will call themselves as
long as the root node passed to it is not null. They only differ in the order the three steps
are executed:
*/

void inOrder(TreeNode *root, DISPLAY display) {
    if(root != NULL) {
        inOrder(root->left, display);
        display(root->data);
        inOrder(root->right, display);
    }
}

void postOrder(TreeNode *root, DISPLAY display) {
    if(root != NULL) {
        postOrder(root->left, display);
        postOrder(root->right, display);
        display(root->data);
    }
}

void preOrder(TreeNode *root, DISPLAY display) {
    if(root != NULL) {
        display(root->data);
        preOrder(root->left, display);
        preOrder(root->right, display);
    }
}

int main() {
    TreeNode *tree = NULL;

    Employee *samuel = (Employee *)malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;

    Employee *sally = (Employee *)malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;

    Employee *susan = (Employee *)malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;

    insertNode(&tree, (COMPARE)compareEmployee, samuel);
    insertNode(&tree, (COMPARE)compareEmployee, sally);
    insertNode(&tree, (COMPARE)compareEmployee, susan);

    preOrder(tree, (DISPLAY) displayEmployee);
    inOrder(tree, (DISPLAY) displayEmployee);
    postOrder(tree, (DISPLAY) displayEmployee);

    free(samuel);
    free(sally);
    free(susan);

    return 0;
}