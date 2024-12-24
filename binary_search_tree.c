#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node* root){
    if (root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
    
}

int isBsT(struct node* root){
    static struct node* prev = NULL;
    if (root!=NULL)
    {
        if (!isBsT(root->left)) return 0;
        if (prev!=NULL && root->data <= prev->data) return 0;
        prev = root;
        return isBsT(root->right);
    }
    
    return 1;
}

int main(){
    struct node* p = createNode(9);
    struct node* p1 = createNode(5);
    struct node* p2 = createNode(12);
    struct node* p11 = createNode(3);
    struct node* p12 = createNode(6);

    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    inOrder(p);
    printf("\n");
    printf("%d ",isBsT(p));

    return 0;
}


