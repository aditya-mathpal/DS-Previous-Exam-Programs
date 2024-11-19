/*
Write the functions countNonleaf to count the number of leaf nodes in a binary tree and tree_path to
find the path from given node to the root.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* lChild;
    struct node* rChild;
} TreeNode;

TreeNode* getNode(int x) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = x;
    temp->lChild = temp->rChild = NULL;
    return temp;
}

TreeNode* buildTree(TreeNode* root) {
    if(root == NULL) {
        printf("Enter data for root node (-1 for no data): ");
        int x;
        scanf("%d",&x);
        if(x==-1) return NULL;
        root = getNode(x);
    }
    printf("%d left child: ",root->data);
    int x;
    scanf("%d",&x);
    if(x!=-1) root->lChild = getNode(x);
    printf("%d right child: ",root->data);
    scanf("%d",&x);
    if(x!=-1) root->rChild = getNode(x);
    if(root->lChild) root->lChild = buildTree(root->lChild);
    if(root->rChild) root->rChild = buildTree(root->rChild);
    return root;
}

void countNonleaf(TreeNode* root, int* x) {
    if(root == NULL) return;
    if(root->lChild == NULL && root->rChild == NULL) return;
    (*x)++;
    countNonleaf(root->lChild,x);
    countNonleaf(root->rChild,x);
}

int isAncestor(TreeNode* ancestor, TreeNode* child) {
    if(ancestor == NULL) return 0;
    if(ancestor->rChild == child || ancestor->lChild == child) return 1;
    return isAncestor(ancestor->lChild,child) || isAncestor(ancestor->rChild,child);
}

void tree_path(TreeNode* root, TreeNode* child) {
    if(root==child) {
        printf("%5d",root->data);
        return;
    }
    if(isAncestor(root->lChild,child)) tree_path(root->lChild,child);
    else tree_path(root->rChild,child);
    printf("%5d",root->data);
}

int main() {
    TreeNode* root = NULL;
    root = buildTree(root);
    printf("Tree Built.\n");
    int num;
    countNonleaf(root,&num);
    printf("%d non-leaf nodes.\n",num);
    TreeNode* temp = root;
    while(temp->rChild != NULL) temp = temp->rChild;
    // printing path of rightmost node to root
    tree_path(root,temp);
    return 0;
}

/*
sample output:
Enter data for root node (-1 for no data): 1
1 left child: 2
1 right child: 3
2 left child: 4
2 right child: 5
4 left child: -1
4 right child: -1
5 left child: -1
5 right child: -1
3 left child: 6
3 right child: 7
6 left child: -1
6 right child: -1
7 left child: -1
7 right child: -1
Tree Built.
3 non-leaf nodes.
    7    3    1
*/