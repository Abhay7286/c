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

struct node* search(struct node* root, int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data > key){
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

int main(){
    struct node* p = createNode(50);
    struct node* p1 = createNode(40);
    struct node* p2 = createNode(60);
    struct node* p11 = createNode(30);
    struct node* p12 = createNode(45);
    struct node* p21 = createNode(57);
    struct node* p22 = createNode(55);

    p->left = p1;
    p->right = p2;

    p1->left = p11;
    p1->right = p12;

    p2->left = p21;
    p2->right = p22;

    struct node* s = search(p, 57);
    if(s!=NULL){
    printf("Found: %d", s->data);
    }
    else{
        printf("Element not found");
    }

    return 0;
}


