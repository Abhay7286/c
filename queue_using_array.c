#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q){
    return q->rear == q->front;
}

int isFull(struct queue *q){
    return q->rear == q->size-1;
}

void enqueue(struct queue *q, int val){
    if (isFull(q))
    {
        printf("queue is full");
        return;
    }
    q->rear++;
    q->arr[q->rear] = val;
    printf("enqueued element is %d\n",val);
}

int dequeue(struct queue *q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("queue is empty");
    }
    else{
        q->front++;
        a = q->arr[q->front];
        return a;
    }
    return a;
}

int peek(struct queue *q, int position){
    int index = q->front + position;
    if (isEmpty(q)|| index>q->rear|| position<=0)
    {
        printf("invalid position");
        return -1;
    }
    else{
        int val = q->arr[index];
        printf("Element at the %d position is %d",position,val);
        return val;
    }
    
}

int main(){
    struct queue q;
    q.size = 6;
    q.front = q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    printf("Queue is empty: %d\n", isEmpty(&q)); 

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Queue is empty: %d\n", isEmpty(&q)); 

    // dequeue(&q);
    // dequeue(&q);

    peek(&q,3);



    free(q.arr);
    return 0;
}