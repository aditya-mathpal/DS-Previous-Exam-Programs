/*
Discover the suitable data structure for handling the Call in Customer care justify your answer and
 implement the code for it.
*/

// solution
// the suitable data structure is any FIFO data structure, e.g. a queue.

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int arr[100];
    int front, rear;
} queue;

void init(queue* q) {
    q->front = q->rear = -1;
}

void enqueue(queue* q, int x) {
    if((q->rear+1)%100 == q->front) {
        printf("Queue is full.\n");
        return;
    }
    if(q->front == -1) q->front++;
    q->rear = (q->rear+1)%100;
    q->arr[q->rear] = x;
    printf("Customer ID %d added to queue.\n",x);
}

int dequeue(queue* q) {
    if(q->front==-1) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->arr[q->front];
    if(q->front==q->rear) init(q);
    else q->front = (q->front+1)%100;
    printf("Customer ID %d will be attended to.\n",x);
    return x;
}

// display and main function to test
void display(queue q) {
    if(q.front==-1) {
        printf("Queue is empty.\n");
        return;
    }
    if(q.front<q.rear) {
        for(int i=q.front;i<=q.rear;i++) {
            printf("%d\n",q.arr[i]);
        }
    }
    else if(q.front>q.rear) {
        for(int i=q.front;i<100;i++) {
            printf("%d\n",q.arr[i]);
        }
        for(int i=0;i<=q.rear;i++) {
            printf("%d\n",q.arr[i]);
        }
    }
    else printf("%d\n",q.arr[q.rear]);
}

int main() {
    queue q;
    init(&q);
    printf("Enter 1 to enter customer to queue, 2 to attend to customer, 3 to display queue, Ctrl-C to exit.\n");
    while(1) {
        int c;
        printf("> ");
        scanf("%d",&c);
        if(c==1) {
            printf("Enter customer ID: ");
            int cid;
            scanf("%d",&cid);
            enqueue(&q,cid);
        }
        else if(c==2) dequeue(&q);
        else if(c==3) display(q);
        else printf("Enter valid input.\n");
    }
    return 0;
}

/*
sample output:
Enter 1 to enter customer to queue, 2 to attend to customer, 3 to display queue, Ctrl-C to exit.
> 1
Enter customer ID: 20
Customer ID 20 added to queue.
> 1
Enter customer ID: 30
Customer ID 30 added to queue.
> 1
Enter customer ID: 40
Customer ID 40 added to queue.
> 3
20
30
40
> 2
Customer ID 20 will be attended to.
> 3
30
40
> 2
Customer ID 30 will be attended to.
> 3
40
> 2
Customer ID 40 will be attended to.
> 3
Queue is empty.
>
*/