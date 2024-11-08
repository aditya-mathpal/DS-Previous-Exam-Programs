// Reverse the elements of a queue

// queue declaration
#include<stdio.h>
#define MAX 100

typedef struct {
    int x[MAX];
    int front;
    int rear;
} queue;

void init(queue *q) {
    q->front = q->rear = -1;
}

int isFull(queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(queue *q) {
    return q->front == -1;
}

void enqueue(queue *q, int x) {
    if (isFull(q))
        printf("\nOverflow\n");
    else {
        q->x[++q->rear] = x;
        if (q->front == -1) q->front = 0;
    }
}

int dequeue(queue *q) {
    int x;
    if (isEmpty(q))
        printf("\nUnderflow!!!\n");
    else if (q->front == q->rear) {
        x = q->x[q->front];
        q->front = q->rear = -1;
        return x;
    }
    else return q->x[q->front++];
}

void displayq(queue q) {
    int i;
    if (isEmpty(&q))
        printf("\nQueue is Empty!!!");
    else {
        printf("\nQueue is:\n");
        for (i = q.front; i <= q.rear; i++)
            printf("%5d", q.x[i]);
    }
    printf("\n");
}

// solution
void Reverse(queue *q) {
    if(isEmpty(q)) return;
    int x = dequeue(q);
    Reverse(q);
    enqueue(q,x);
}

// testing
int main() {
    queue q;
    init(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    displayq(q);
    Reverse(&q);
    printf("After reversal");
    displayq(q);
    return 0;
}

/*
output:
Queue is:
   10   20   30   40   50
After reversal
Queue is:
   50   40   30   20   10
*/