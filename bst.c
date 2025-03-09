#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int val;
    struct Node* root = NULL;
    while(1)
    {  int ch;
        printf("Enter 1 to Enter\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
              {
                printf("Enter value to insert in the tree :");
                scanf("%d",&val);
                root = insert(root, val);
                inorderTraversal(root);
                printf("\n");
              }
                 break;

            default:
            exit(0);
          
        }
    }

    freeTree(root);
    return 0;
}
