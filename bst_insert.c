#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node *new = createNode(key);

    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    struct node *p = createNode(50);
    struct node *p1 = createNode(40);
    struct node *p2 = createNode(60);
    struct node *p11 = createNode(30);
    struct node *p12 = createNode(45);
    struct node *p21 = createNode(57);
    struct node *p22 = createNode(55);

    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    p2->left = p21;
    p2->right = p22;

    insert(p, 40);

    return 0;
}
