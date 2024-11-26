#include <stdio.h>
#include <stdlib.h>

struct circularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct circularQueue *q) {
    return q->rear == q->front;
}

int isFull(struct circularQueue *q) {
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(struct circularQueue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;
    printf("Enqueued element: %d\n", val);
}

int dequeue(struct circularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front = (q->front + 1) % q->size;
    int val = q->arr[q->front];
    printf("Dequeued element: %d\n", val);
    return val;
}

int peek(struct circularQueue *q, int position) {
    if (isEmpty(q) || position <= 0 || position > q->size - 1) {
        printf("Invalid position\n");
        return -1;
    }
    int index = (q->front + position) % q->size;
    int val = q->arr[index];
    printf("Element at position %d: %d\n", position, val);
    return val;
}

int main() {
    struct circularQueue q;
    q.size = 6;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Queue is empty: %d\n", isEmpty(&q));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6); 

    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 7); 
    enqueue(&q, 8);

    peek(&q, 3);

    printf("Queue is empty: %d\n", isEmpty(&q));

    free(q.arr);
    return 0;
}
