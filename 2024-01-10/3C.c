/*
Write a function to insert an item at the end of Circular Singly Linked List. Use the following function
 prototype:
 Nodeptr InsertLast(Nodeptr last, int item); where last points to the last node of linked list.
*/

// test code
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int item;
    struct node* right;
} *Nodeptr;

Nodeptr getNode(int item) {
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct node));
    temp->item = item;
    temp->right = NULL;
    return temp;
}

// solution
Nodeptr InsertLast(Nodeptr last, int item) {
    if(last==NULL) {
        Nodeptr temp = getNode(item);
        temp->right = temp;
        return temp;
    }
    Nodeptr head = last->right;
    Nodeptr temp = getNode(item);
    temp->right = head;
    last->right = temp;
    return head;
}

// test code continues
void display(Nodeptr head) {
    if(head==NULL) {
        printf("Empty list.\n");
        return;
    }
    Nodeptr temp = head;
    do {
        printf("%5d",temp->item);
        temp = temp->right;
    } while(temp!=head);
    printf("\n");
}

int main() {
    Nodeptr head = NULL;
    head = InsertLast(head,1);
    head = InsertLast(head,2);
    display(head);
    head = InsertLast(head->right,3); //manually inputting the pointer to the last node
    display(head);
    return 0;
}

/*
output:
    1    2
    1    2    3
*/