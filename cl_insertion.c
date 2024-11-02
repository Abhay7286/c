#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void ListTraversal(struct Node *head)
{
    struct Node* ptr = head;
    do
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    
};

struct Node *insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;

    while (p->next!=head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
    
};

struct Node *insertAtIndex(struct Node *head,int data,int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    int count = 0;

    // Traverse to the node just before the desired index
    while (count < index - 1 && p->next != head) {
        p = p->next;
        count++;
    }

    // Insert the node if we have reached the right position
    if (count == index - 1) {
        ptr->next = p->next;
        p->next = ptr;
    } 
    else {
        // If the index is out of bounds (greater than the size of the list)
        printf("Index out of bounds\n");
        free(ptr);
    }

    return head;

};

struct Node *insertAtLast(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    
    while (p->next!=head)
    {
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
    

    return head;

};

struct Node *insertAfterNode(struct Node *head,int data,struct Node* prenode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prenode->next;
    prenode->next = ptr;
    

    return head;

};

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = head;

    printf("Linked List before operation\n");
    ListTraversal(head);
    
    printf("Linked List after Insertion\n");
    // head = insertAtFirst(head,100);
    // head = insertAtIndex(head,33,2);
    // head = insertAtLast(head,56545);
    head = insertAtLast(head,999,second);
    ListTraversal(head);
    
}