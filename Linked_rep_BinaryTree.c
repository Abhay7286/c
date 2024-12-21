#include <stdio.h>
#include <stdlib.h>  

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));  // Allocate memory for a new node
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;  // Return the pointer to the newly created node
}

int main() {
    struct node* p = createNode(2);   // Create root node
    struct node* p1 = createNode(3);  // Create left child
    struct node* p2 = createNode(4);  // Create right child

    p->left = p1;  // Link left child
    p->right = p2; // Link right child

    // Example tree is now:
    //       2
    //      / \
    //     3   4

    return 0;
}
