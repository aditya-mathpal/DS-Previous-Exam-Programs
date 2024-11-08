/*
Prepare a complete C program consisting of a function sortedInsert(. . .) to insert an integer into a
sorted doubly linked list, such that after insertion the list remains sorted. Also, include a function to
display the contents of the list.
*/

// solution
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *NODE;

NODE getNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE insertR(NODE head, int x) {
    if(head==NULL) return getNode(x);
    NODE temp = head;
    while(temp->right!=NULL) {
        temp = temp->right;
    }
    temp->right = getNode(x);
    temp->right->left = temp;
    return head;
}

NODE sortedInsert(NODE head, int x) {
    if(head==NULL) return getNode(x);
    NODE temp = head;
    if(temp->data >= x) {
        NODE a = getNode(x);
        a->right = head;
        head->left = a;
        return a;
    }
    while(temp->right!=NULL && temp->right->data < x) {
        temp = temp->right;
    }
    NODE a = getNode(x);
    a->left = temp;
    a->right = temp->right;
    temp->right = a;
    if(a->right!=NULL) a->right->left = a;
    return head;
}

void display(NODE head) {
    while(head!=NULL) {
        printf("%5d",head->data);
        head = head->right;
    }
    printf("\n");
}

void freeList(NODE head) {
    if(head==NULL) return;
    freeList(head->right);
    free(head);
}

int main() {
    NODE head = getNode(1);
    insertR(head,2);
    insertR(head,4);
    insertR(head,5);
    printf("Initial list:\n");
    display(head);
    sortedInsert(head,3);
    printf("After adding 3:\n");
    display(head);
    freeList(head);
    return 0;
}

/*
sample output:
Initial list:
    1    2    4    5
After adding 3:
    1    2    3    4    5
*/