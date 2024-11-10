/*
Write functions to
i) Check whether binary trees are structurally identical or not.
ii) Merge two binary trees by summing their values.
*/

// declarations for testing
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *right, *left;
} Node;

Node* getNode(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->right = temp->left = NULL;
    return temp;
}

Node* buildTree() {
    int data;
    printf("> ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    Node* newNode = getNode(data);
    printf("Building left subtree of %d:\n", data);
    newNode->left = buildTree();
    printf("Building right subtree of %d:\n", data);
    newNode->right = buildTree();
    return newNode;
}

// just copied this to verify program via output
void printTree(Node* root, int level) {
    if (root == NULL) return;

    printTree(root->right, level + 1);  // Print right child first for a visual effect

    // Print current node with indentation based on the level
    for (int i = 0; i < level; i++) printf("    ");  // 4 spaces per level
    printf("%d\n", root->data);

    printTree(root->left, level + 1);   // Then print left child
}


//solution
int check(Node* rootA, Node* rootB) {
    if(rootA == NULL && rootB == NULL) return 1;
    if(rootA == NULL || rootB == NULL) return 0;
    return check(rootA->left,rootB->left) && check(rootA->right,rootB->right);
}

Node* merge(Node* rootA, Node* rootB) {\
    if(rootA == NULL && rootB == NULL) return NULL;
    if(!check(rootA,rootB)) {
        printf("Trees are not structuarlly idential\n");
        return NULL;
    }
    Node* result = getNode(rootA->data += rootB->data);
    result->left = merge(rootA->left,rootB->left);
    result->right = merge(rootA->right,rootB->right);
    return result;
}

// testing
int main() {
    printf("Building Tree A, enter node value (-1 for no node):\n");
    Node* TreeA = buildTree();
    printf("Building Tree B, enter node value (-1 for no node):\n");
    Node* TreeB = buildTree();
    printf("Tree A before merging:\n");
    printTree(TreeA, 0);
    printf("Tree B before merging:\n");
    printTree(TreeB, 0);
    Node* sum = merge(TreeA,TreeB);
    printf("Result:\n");
    printTree(sum,0);
    return 0;
}

/*
sample output:
Building Tree A, enter node value (-1 for no node):
> 1
Building left subtree of 1:
> 2
Building left subtree of 2:
> 4
Building left subtree of 4:
> -1
Building right subtree of 4:
> -1
Building right subtree of 2:
> 5
Building left subtree of 5:
> -1
Building right subtree of 5:
> -1
Building right subtree of 1:
> 3
Building left subtree of 3:
> 6
Building left subtree of 6:
> -1
Building right subtree of 6:
> -1
Building right subtree of 3:
> 7
Building left subtree of 7:
> -1
Building right subtree of 7:
> -1
Building Tree B, enter node value (-1 for no node):
> 2
Building left subtree of 2:
> 3
Building left subtree of 3:
> 5
Building left subtree of 5:
> -1
Building right subtree of 5:
> -1
Building right subtree of 3:
> 6
Building left subtree of 6:
> -1
Building right subtree of 6:
> -1
Building right subtree of 2:
> 4
Building left subtree of 4:
> 7
Building left subtree of 7:
> -1
Building right subtree of 7:
> -1
Building right subtree of 4:
> 8
Building left subtree of 8:
> -1
Building right subtree of 8:
> -1
Tree A before merging:
        7
    3
        6
1
        5
    2
        4
Tree B before merging:
        8
    4
        7
2
        6
    3
        5
Result:
        15
    7
        13
3
        11
    5
        9
*/