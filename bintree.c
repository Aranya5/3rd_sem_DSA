#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}bnode;

bnode *createNode(int val){
    bnode *new = (bnode*)malloc(sizeof(int));
    if(new != NULL){
    new->data = val;
    new->right = NULL;
    new->left = NULL;
    }
    return new;
}

int main(){
    bnode *root = NULL;
    int x,ch;
    printf("Enter value of ROOT node");
    scanf("%d",&x);
    root = createNode(x);
    if(root->data != NULL){
        while(1){
        printf("\n Enter 1 to insert the RIGHT node \n Enter 2 to insert the LEFT node \n Enter 3 to go back to node \n Enter 4 to EXIT");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            
        }
    }

    }
    


}

