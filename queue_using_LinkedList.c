#include <stdio.h>
#include <stdlib.h>

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val){
    struct Node*n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("queue is full\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(front == NULL){
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct Node*ptr = front;
    if(front==NULL){
        printf("queue is empty\n");
    }
    else{
        front = front->next;
        val = front->data;
        free(ptr);
    }
    return val;
}

int main(){
    linkedListTraversal(front);
    enqueue(23);
    enqueue(13);
    linkedListTraversal(front);
    printf("dequeued element: %d\n",dequeue());

    return 0;
}